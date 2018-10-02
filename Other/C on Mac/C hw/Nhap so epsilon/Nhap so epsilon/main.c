#include <stdio.h>

int main() {
    float n;
    scanf("%f",&n);
    int giaithua = 1;
    float e = 1;
    int i = 1;
    if (n==0||n>=1) {
        printf("Nhap so n<1");
    } else {
        while(giaithua<=(1/n)) {
            giaithua *= i;
            i++;
            e += 1.0/giaithua;
        }
        printf("%f\n",e);
    }
}