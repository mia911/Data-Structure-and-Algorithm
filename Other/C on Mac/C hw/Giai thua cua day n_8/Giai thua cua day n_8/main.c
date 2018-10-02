#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int giaithua = 1;
    if(n<0||n>=8) {
        printf("Nhap so duong n<8\n");
    } else {
    for(int i=1; i<(n+1); i++) {
        giaithua *= i;
    }
        printf("%d\n", giaithua);
    }
    
    return 0;
}