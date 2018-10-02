//Viet ham giai phuong trinh bac 2 su dung con tro

#include <stdio.h>
#include <math.h>

int quadratic (float, float, float, float*, float*);
int main() {
    float a, b, c, x1, x2;
    printf("Input a: "); scanf("%f", &a);
    printf("Input b: "); scanf("%f", &b);
    printf("Input c: "); scanf("%f", &c);
    float delta = pow(b, 2) - 4*a*c;
    int root = quadratic(a, b, c, &x1, &x2);
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("There are no root for this equation\n");
            } else {
                printf("There are unlimited of roots for this equation\n");
            }
        } else {
            printf("There is one root for this equation: %.2f\n", -c/b);
        }
    } else {
        if (root == 0) {
            printf("There is one root for this equation: %.2f\n", x1);
        } else if (root == 1) {
            printf("There are two roots for this equation: \n");
            printf("\t x1 = %.2f\n", x1);
            printf("\t x2 = %.2f\n", x2);
        } else {
            printf("There are two complex roots for this equation: \n");
            printf("\t x1 = (-%.2f - i * %.2f)/%.2f\n", b, sqrt(-delta), 2*a);
            printf("\t x2 = (-%.2f + i * %.2f)/%.2f\n", b, sqrt(-delta), 2*a);
        }
    }
    return 0;
}

int quadratic (float a, float b, float c, float *x1, float *x2) {
    float delta = pow(b, 2) - 4*a*c;
    if (delta > 0) {
        *x1 = (-b - sqrt(delta))/2*a;
        *x2 = (-b + sqrt(delta))/2*a;
        return 1;
    } else if (delta == 0) {
        *x1 = *x2 = -b/(2*a);
        return 0;
    } else {
        return -1;
    }
}