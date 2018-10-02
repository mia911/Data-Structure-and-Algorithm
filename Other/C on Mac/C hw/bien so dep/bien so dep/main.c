#include <stdio.h>
#include <math.h>

int reverse (int x);
int nguyento (int y);
int main() {
    int a, b;
    do {
        printf("Nhap a:\n");
        scanf("%d",&a);
        printf("Nhap b:\n");
        scanf("%d",&b);
    } while (a < pow(10,4) || b < a || b >= pow(10,5)) ;
    
    int i = a;
    int dem = 0;
    for (i=a; i<=b; i++) {
        if (nguyento(i)) {
            if (reverse(i)) {
            dem ++;
            }
        }
    }
    
    printf("%d\n",dem);
    return 0;
}

int nguyento (int y) {
    int j = 2;
    int flag = 1;
    for (j=2; j<(y/2); j++) {
        if (y % j == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int reverse (int x) {
    if ((x%100)%10 == (x/1000)/10 && (x%100)/10 == (x/1000)%10) {
        return 1;
    }
    return 0;
}
