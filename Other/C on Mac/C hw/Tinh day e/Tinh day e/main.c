#include<stdio.h>
#include<math.h>

int main() {
    float n;
    do{
        printf("\n Nhap n (0 < n < 1) = ");
        scanf("%f",&n);
    }while(n>=1 || n<=0);
    int i = 0;
    float PI;
    do {
        PI = 4*(pow((-1),i)*(1.0/((2*i)+1)));
        i++;
    } while (i<=floor(((1/n)-1)/2));
    printf("%f\n",PI);
    return 0;
}

