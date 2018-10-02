#include <stdio.h>
#include <math.h>
int main() {
    float s1 = 1;
    float s2 = 1;
    float s3 = 1;
    float x;
    int n;
    scanf("%d",&n);
    scanf("%f",&x);
    float giaithua = 1;
    for(int i = 1; i<n+1; i++) {
        giaithua = giaithua*i;
        s1 += pow(x,i);
        s2 += pow(-1,i)*pow(x,i);
        s3 += pow(x,i)/giaithua;
    }
    printf ("%f\n",s1);
    printf ("%f\n",s2);
    printf ("%f\n",s3);
}