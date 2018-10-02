#include <stdio.h>

int main() {
    int n;
    do{
        printf("Nhap so nguyen duong n = ");
        scanf("%d",&n);
    } while(n<=0);
    int nguyento = 0;
    if(n==1) {
        nguyento = 0;
    } else if (n==2) {
        nguyento = 1;
    } else {
    for (int i = 2; i<(n/2); i++) {
        if (n%i==0) {
            nguyento = 1;
        } else {
            nguyento = 0;
        }
    }
    }
    if (nguyento ==0) {
        printf("Day khong phai la so nguyen to\n");
    } else {
        printf("Day la so nguyen to\n");
    }
    return 0;
}