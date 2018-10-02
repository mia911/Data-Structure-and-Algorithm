#include <stdio.h>

int main() {
    int i=0;
    int j=0;
    int k=0;
    int n=0;
    int soam=0;
    int soduong=0;
    float a[1024];
    float b[1024];
    float c[1024];
    float x=0;
    
    
    do {
    printf("Nhap cac so: ");
    scanf("%f",&x);
    a[i]=x;
    i++;
    n++;
    } while (n<10);
    
    for (i=0; i<n;i++) {
        if (a[i]<0) {
            c[j]=a[i];
            j++;
            soam+=1;
        } else if (a[i]>0) {
            b[k]=a[i];
            k++;
            soduong+=1;
        }
    }
    
    printf("\n\nDay cac so am la: ");
    for (j=0;j<soam;j++) {
        printf("%.3f ",c[j]);
    }
    
    printf("\n\nDay cac so duong la: ");
    for (k=0;k<soduong;k++) {
        printf("%.3f ",b[k]);
    }
    return 0;
}
