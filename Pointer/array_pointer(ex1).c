#include <stdio.h>

void input_matrix(float *, int, int);
void show_matrix(float *, int, int);
void multi_matrix (float *, float *, float *, int, int , int);
float *multiply (float *, float *, int , int, int);

int main() {
    float a[3][4], b[4][2], c[3][2];
    
    printf("Nhap ma tran a:\n");input_matrix(a, 3, 4);
    printf("Nhap ma tran b:\n");input_matrix(b, 4, 2);
    multi_matrix(a, b, c, 3, 4, 2);
    
    printf("Ma tran a:\n"); show_matrix(a, 3, 4);
    printf("Ma tran b:\n"); show_matrix(b, 4, 2);
    printf("Ma tran c = a*b \n"); show_matrix(multiply(a, b, 3, 4, 2), 3, 2);
    printf("Ma tran c = a*b \n"); show_matrix(c, 3, 2);
    
    return 0;
}

void input_matrix(float *pM, int m, int n) {
    int size = m*n;
    int i, j, t;
    float temp;
    for (t=0; t<size; t++) {
        i = t/n;
        j = t - (i*n);
        printf("\t Phan tu thu %d, %d: ", i+1, j+1);
        scanf("%f", &temp);
        *(pM+t) = temp;
    }
}

void show_matrix(float *pM, int m, int n) {
    int size = m*n;
    int t;
    for (t=0; t<size; t++) {
        int count = (t+1)%n;
        printf("\t %10.2f %c", *(pM + t), count?' ':'\n');
    }
}

void multi_matrix (float *pa, float *pb, float *pc, int m, int n , int k) {
    int i, j, t;
    for (i=0; i<m; i++) {
        for (j=0; j<k; j++) {
            float sum_temp = 0;
            for (t=0; t<n; t++) {
                float pa_i_t = *(pa + i*n + t);
                float pb_t_j = *(pb + t*k + j);
                sum_temp += pa_i_t * pb_t_j;
            }
            *(pc + i*k + j) = sum_temp;
        }
    }
}

float *multiply (float *pa, float *pb, int m, int n , int k) {
    int i, j, t;
    float *pc = calloc(m*k, sizeof(float));
    for (i=0; i<m; i++) {
        for (j=0; j<k; j++) {
            float sum_temp = 0;
            for (t=0; t<n; t++) {
                float pa_i_t = *(pa + i*n + t);
                float pb_t_j = *(pb + t*k + j);
                sum_temp += pa_i_t * pb_t_j;
            }
            *(pc + i*k + j) = sum_temp;
        }
    }
    return pc;
}
