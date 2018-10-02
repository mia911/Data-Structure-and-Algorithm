//Giai phuong trinh bac 2 su dung ham

#include <stdio.h>
#include <math.h>

typedef struct complex_struct {
    float real;
    float imaginary;
} complex;

int root_ext (float, float, float, complex*, complex*);

int main() {
    complex *x1;
    complex *x2;
    float a, b, c;
    printf("Input a: "); scanf("%f", &a);
    printf("Input b: "); scanf("%f", &b);
    printf("Input c: "); scanf("%f", &c);
    
    int root = root_ext(a, b, c, x1, x2);
    
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
            printf("There is one root for this equation: %.2f\n", x1->real);
        } else if (root == 1) {
            printf("There are two roots for this equation: \n");
            printf("\t x1 = %.2f\n", x1->real + x1->imaginary);
            printf("\t x2 = %.2f\n", x2->real + x2->imaginary);
        } else {
            printf("There are two complex roots for this equation: \n");
            printf("\t x1 = %.2f - i * %.2f\n", x1->real, x1->imaginary);
            printf("\t x2 = %.2f + i * %.2f\n.", x2->real, x2->imaginary);
        }
    }
    return 0;
}

int root_ext (float a, float b, float c, complex *x1, complex *x2) {
    float delta = pow(b, 2) - 4*a*c;
    if (delta > 0) {
        x1->real = -b/(2*a);
        x1->imaginary = - sqrt(fabs(delta))/(2*a);
        x2->real = -b/(2*a);
        x2->imaginary = sqrt(fabs(delta))/(2*a);
        return 1;
    } else if (delta == 0) {
        x1->real = x2->real = -b/(2*a);
        return 0;
    } else {
        x1->real = -b/(2*a);
        x1->imaginary = - sqrt(fabs(delta))/(2*a);
        x2->real = -b/(2*a);
        x2->imaginary = sqrt(fabs(delta))/(2*a);
        return -1;
    }
}

