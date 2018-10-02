#include <stdio.h>

int main() {
    int n;
    printf("Nhap n: "); scanf ("%d", &n);
    
    int prime[n];
    int index = 1;
    int i = 0;
    int j = 0;
    int flag = 1;
    prime[0] = 2;
    for (i=3; i<n; i++) {
        for (j=2; j<i; j++) {
            flag = 1;
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            prime[index] = i;
            index ++;
        }
    }
    
    int m = n;
    printf("%d = ", m);
    while (n != 1) {
        if (n != m) {
            printf(" * ");
        }
        for (i=0; i<index; i++) {
            if (n % prime[i] == 0) {
                n /= prime[i];
                printf("%d", prime[i]);
                break;
            }
        }
        
        if (i == index) {
            printf("%d", m);
            break;
        }
    }
    printf("\n");
        return 0;
}


