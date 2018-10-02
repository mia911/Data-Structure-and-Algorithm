#include <stdio.h>

int main () {
    float a, b, c, d;
    printf("Input a: "); scanf ("%f", &a);
    printf("Input b: "); scanf ("%f", &b);
    printf("Input c: "); scanf ("%f", &c);
    printf("Input d: "); scanf ("%f", &d);
    
    float x1, x2;
    x1 = -b/a;
    x2 = -d/c;
    if ((a == 0 && b < 0) || (c == 0 && d < 0)) {
        printf("There is no root for this inequation.\n");
    } else if ((a == 0 && b > 0) && (c == 0 && d >0)) {
        printf("There are infinite roots for this inequation.\n");
    } else {
        if (a > 0) {
            if (c > 0) {
                if (x1 >= x2) {
                    printf("x > %.2f\n", x1);
                } else if (x1 < x2) {
                    printf("x > %.2f\n", x2);
                }
            } else if (c < 0) {
                if (x1 > x2) {
                    printf("There is no root for this inequation.\n");
                } else if (x1 <= x2) {
                    printf("%.2f < x < %.2f\n", x1, x2);
                }
            }
        } else if (a < 0) {
            if (c > 0) {
                if (x1 > x2) {
                    printf("%.2f < x < %.2f\n", x2, x1);
                } else if (x1 <= x2) {
                    printf("There is no root for this inequation.\n");
                }
            } else if (c < 0) {
                if (x1 >= x2) {
                    printf("x < %.2f\n", x1);
                } else if (x1 < x2) {
                    printf("x < %.2f\n", x2);
                }
            }
        }
    }
    
    return 0;
}