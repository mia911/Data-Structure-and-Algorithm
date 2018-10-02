#include<stdio.h>

int main() {
    int a, b;
    do {
        printf("Nhap 2 so nguyen a va b");
        scanf("%d %d",&a,&b);
    } while (a > 0 && b > 0);
    
    int c = a - b;
    do {
        if (c < 0) {
            b = -c;
        } else if (c > 0) {
            a = c;
        }
    } while (c != 0);
    
    
}