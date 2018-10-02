#include <stdio.h>
#include <string.h>

int main() {
    char dslop[10][30];
    int n;
    int i=0;

    printf("So luong hoc sinh trong lop la: ");
    scanf("%d",&n);
    
    printf("Nhap ten cac hoc sinh trong lop:\n");
    while (i<n) {
        scanf("%99s",dslop[i]);
        i++;
    }
    
    for (int k=0;k<n-1;k++) {
        for (int l=k+1;l<n;l++) {
            if(strcmp(dslop[k],dslop[l])<0) {
                char trunggian[30];
                strcpy(trunggian,dslop[k]);
                strcpy(dslop[k],dslop[l]);
                strcpy(dslop[l],trunggian);
            }
        }
    }
    
    printf("\n Danh sach lop theo thu tu ABC la: ");
    for (i = 0;i<n;i++) {
        puts(dslop[i]);
    }
    return 0;
}