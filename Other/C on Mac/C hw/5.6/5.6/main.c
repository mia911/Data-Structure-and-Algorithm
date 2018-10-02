#include <stdio.h>

int main() {
    int m,n;
    printf("Nhap kich thuoc cua ma tran: ");
    printf("m = "); scanf("%d",&m);
    printf("n = "); scanf("%d",&n);
    
    float a[100][100];
    float b[100][100];
    float c[100][100];
    
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("a[%d][%d]: ",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    printf("\n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("b[%d][%d]: ",i,j);
            scanf("%f",&b[i][j]);
        }
    }
    
    printf("Cac phan tu cua ma tran c la: \n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            c[i][j]=a[i][j]+b[i][j];
            printf("%f  ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}