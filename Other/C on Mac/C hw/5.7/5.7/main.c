#include <stdio.h>

int main(){
    int m, k, n;
    printf("\n Nhap kich thuoc cua ma tran A, B:");
    printf("\n  So hang m = "); scanf("%d",&m);
    printf("\n  So cot (cot A = hang B) k = "); scanf("%d",&k);
    printf("\n  So cot n= "); scanf("%d",&n);
    
    float A[m][k], B[k][n];
    printf("\n Nhap cac phan tu cua ma tran A\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            printf("A[%d][%d] = ",i,j);
            scanf("%f",&A[i][j]);
        }
    }
    
    printf("\n Nhap cac phan tu cua ma tran B\n");
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            printf("B[%d][%d] = ",i,j);
            scanf("%f",&B[i][j]);
        }
    }
    
    //tinh tong C = A*B
    float C[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            float temp=0;
            for(int t=0;t<k;t++){
                temp +=A[i][t]*B[t][j];
            }
            C[i][j]=temp;
        }
    }
    
    //in ket qua
    printf("Ma tran A:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            printf("%f  ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("Ma tran B:\n");
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            printf("%f  ", B[i][j]);
        }
        printf("\n");
    }
    printf("Ma tran C = A*B:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%f  ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}