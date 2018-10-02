#include <stdio.h>

int main(){
    int m, n;
    printf("\n Nhap kich thuoc cua ma tran:");
    printf("\n  So hang m = "); scanf("%d",&m);
    printf("\n  So cot n = "); scanf("%d",&n);
    
    float A[m][n], B[m][n];
    printf("\n Nhap cac phan tu cua ma tran A\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("A[%d][%d] = ",i,j);
            scanf("%f",&A[i][j]);
        }
    }
    
    printf("\n Nhap cac phan tu cua ma tran B\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("B[%d][%d] = ",i,j);
            scanf("%f",&B[i][j]);
        }
    }
    
    //tinh tong C = A+B
    float C[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    
    //in ket qua
    printf("Ma tran A:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%f  ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("Ma tran B:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%f  ", B[i][j]);
        }
        printf("\n");
    }
    printf("Ma tran C = A+B:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%f  ", C[i][j]);
        }
        printf("\n");
    }2
    return 0;
}
