#include <stdio.h>

int main() {
    int n;
    printf("Nhap 1 goc: ");
    scanf("%d", &n);
    
    int m = n;
    if (m < 0) {
        while (m <= (-360)) {
            m += 360;
        }
    } else {
        while (m >= 360) {
            m -= 360;
        }
    }
    
    if (m == 0 || m == 90 || m == 180 || m == 270 || m == (-90) || m == (-180) || m == (-270)) {
        printf("Goc %d thuoc phan tu nao\n", n);
    } else if(m > 0) {
        if (m < 90) {
            printf("Goc %d thuoc phan tu thu 1\n", n);
        } else if (m < 180) {
            printf("Goc %d thuoc phan tu thu 2\n", n);
        } else if (m < 270) {
            printf("Goc %d thuoc phan tu thu 3\n", n);
        } else {
            printf("Goc %d thuoc phan tu thu 4\n", n);
        }
    } else {
        if (m > (-90)) {
            printf("Goc %d thuoc phan tu thu 4\n", n);
        } else if (m > (-180)) {
            printf("Goc %d thuoc phan tu thu 3\n", n);
        } else if (m > (-270)) {
            printf("Goc %d thuoc phan tu thu 2\n", n);
        } else {
            printf("Goc %d thuoc phan tu thu 1\n", n);
        }
    }
    
    return 0;
}