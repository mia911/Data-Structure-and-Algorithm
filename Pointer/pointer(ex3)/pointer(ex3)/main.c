#include <stdio.h>
#include <stdlib.h>

int main() {
    int *num_arr[10];
    int i;
    int tong = 0;
    for (i=0; i<10; i++) {
        printf("Input the %dth number: ", i+1);
        num_arr[i] = malloc(sizeof(int));
        scanf("%d", num_arr[i]);
        tong += *num_arr[i];
    }
    
    int j;
    int *temp;
    for (i=0; i<9; i++) {
        for (j=i+1; j<10; j++) {
            if (*num_arr[i] > *num_arr[j]) {
                temp = num_arr[i];
                num_arr[i] = num_arr[j];
                num_arr[j] = temp;
            }
        }
    }
    printf("Sum of the array is: %d\n", tong);
    printf("The array after being sorted from smallest to largest is: \n");
    for (i=0; i<10; i++) {
        printf("%d  ", *num_arr[i]);
    }
    printf("\n");
    for (i=0; i<10; i++) {
        free(num_arr[i]);
    }
    
    return 0;
}