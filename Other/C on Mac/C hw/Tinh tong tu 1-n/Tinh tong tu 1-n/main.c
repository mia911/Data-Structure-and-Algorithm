#include<stdio.h>

int main() {
    int n;
    int flag = 0;
    do {
        if(flag == 0) {
            printf("Nhap n: ");
        } else if (flag == 1) {
            printf("Ban da nhap sai n\n");
            printf("Nhap lai n:");
        }
        flag = 1;
        scanf("%d",&n);
    }
    while (n<=10||n>=100);
    int tong = 0;
    for (int i = 0; i<(n+1); i++) {
        tong += i;
    }
    printf("%d\n",tong);
    return 0;
}