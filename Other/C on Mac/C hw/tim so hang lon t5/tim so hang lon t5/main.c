#include <stdio.h>

int main() {
    int n;
    do {
        printf("Nhap n: \n");
        scanf("%d",&n);
    } while (n <= 0);
    
    int i;
    int a[n];
    printf("Nhap cac phan tu trong day: \n");
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    
    int k;
    printf("Nhap k: \n");
    scanf("%d",&k);
    
    int j;
    int currentsizeb = 1;
    int b[n];
    b[0] = a[0];
    for (i=1; i<n; i++) {
        for (j=0; j<currentsizeb; j++) {
            if (a[i] == b[j]) {
                break;
            }
        }
        if (j == currentsizeb) {
            b[j] = a[i];
            currentsizeb++;
        }
    }
    
    for (i=0; i<currentsizeb; i++) {
        printf("%d  ",b[i]);
    }
    
    printf("\n");
    
    int trunggian = 0;
    for (i=0; i<currentsizeb; i++) {
        for (j=(i+1); j<currentsizeb; j++) {
            if (b[i] < b[j]) {
                trunggian = b[i];
                b[i] = b[j];
                b[j] = trunggian;
            }
        }
    }
    
    for (i=0; i<currentsizeb; i++) {
        printf("%d  ",b[i]);
    }
    
    printf("\n");
    
    if (k > currentsizeb) {
        printf("Khong tim duoc gia tri lon thu k.\n");
    } else {
        printf("Gia tri lon thu %d la: %d\n", k, b[k-1]);
    }
    
    return 0;
}