#include <stdio.h>

int main() {
    int a1 = 0;
    int a2 = 1;
    int a3 = 0;
    printf("%d  %d", a1, a2);
    while (a3 < 2000 - a2) {
        a3 = a1 + a2;
        printf("%d  ", a3);
        a1 = a2;
        a2 = a3;
    }
    printf("\n");
    return 0;
}