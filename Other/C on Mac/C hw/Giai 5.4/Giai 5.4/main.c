#include <stdio.h>
#include <string.h>
int main(){
    char dslop[10][30];
    int n;
    printf("\n Nhap vao so luong hoc sinh trong lop (<= 10) n = ");
    scanf("%d", &n);
    int i=0;
    while(i<n){
        printf("\n Nhap ten cho hoc sinh thu %d: ",i);
        fflush(stdin);
        gets(dslop[i]);
        i++;
    }
    
    for(int j=0;j<n-1;j++){
        for(int k=j+1;k<n;k++){
            if(strcmp(dslop[j],dslop[k])>0){
                char s[30];
                strcpy(s,dslop[j]);
                strcpy(dslop[j],dslop[k]);
                strcpy(dslop[k], s);
            }
        }
    }
    
    printf("\n Danh sach lop hoc sau sap xep theo thu tu ABC \n");
    for(int i=0;i<n;i++){
        printf("%d. ",i+1);
        puts(dslop[i]);
    }
    
    return 0;
}