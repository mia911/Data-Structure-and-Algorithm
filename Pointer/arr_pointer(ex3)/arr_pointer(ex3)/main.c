//Xay dung chuong trình có:
//- hàm tính bình phương của số thực
//- hàm tính lập phương của só thực
//- so sánh giữa hàm lập phương va bình phương và đưa ra số lớn hơn
//- chương trình được chạy đi chạy lại. khi ng dùng ấn số 0 thì dừng, số 1 thì tiếp

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float square (float *);
float square_root (float *);
int main() {
    int answer = 1;
    while (answer == 1) {
        float *a;
        printf("Input a float: "); scanf("%f", a);
        
        float sqre = square(a);
        float sqre_root = square_root(a);
        
        printf("The larger function is: ");
        if (sqre > sqre_root) {
            printf("the Square function \n");
            printf("\t \t (%.2f > %.2f)", sqre, sqre_root);
        } else {
            printf("the Square Root function \n");
            printf("\t \t (%.2f > %.2f)", sqre_root, sqre);
        }
        
        printf("\nDo you want to continue executing this program? (1/0)");
        scanf("%d", &answer);
        
        if (answer == 0) {
            return 0;
        }
    }
}

float square (float *a) {
    return pow(*a, 2);
}

float square_root (float *a) {
    return sqrt(*a);
}
