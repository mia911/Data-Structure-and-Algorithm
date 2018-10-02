#include<stdio.h>

int main() {
    float arr[1024];
    int count = 0;
    float x;
    int i = 0;
    float tong = 0;
    do {
        printf("Nhap cac so:");
        scanf("%f",&x);
        arr[i] = x;
        i++;
        count += 1;
        } while (x != 0);

    float max = arr[0];
    float min = arr[0];
    for(int j = 0; j<count; j++) {
        tong += arr[j];
        if (max < arr[j]) {
            max = arr[j];
        }
        if (min > arr[j]) {
            min = arr[j];
        }
    }

    printf("%f\n",tong);
    printf("%f\n",max);
    printf("%f\n",min);
    return 0;
}