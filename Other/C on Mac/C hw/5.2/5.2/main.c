#include <stdio.h>
#include <math.h>
int main () {
    int n = 0;
    int i = 0;
    float x;
    float arr[1024];
    do {
        printf("Nhap cac so: ");
        scanf("%f",&x);
        arr[i] = x;
        i++;
        n++;
    } while (n<9);
    
    float trunggian;
    for (int j = 0;j<n-1;j++) {
        for (int k = j +1;k<n;k++) {
            if(arr[j]<arr[k]) {
                trunggian = arr[j];
                arr[j] = arr[k];
                arr[k] = trunggian;
            }
        }
    }
    printf("\n\n Day tu lon den be la: ");
    for (int l= 0;l<n;l++) {
        printf("%f, ",arr[l]);
    }
    
    for (int j = 0;j<n-1;j++) {
        for (int k = j+1;k<n;k++) {
            if(arr[j]>arr[k]) {
                trunggian = arr[j];
                arr[j] = arr[k];
                arr[k] = trunggian;
            }
        }
    }
    printf("\n\n Day tu be den lon la:");
    for (int l= 0;l<n;l++) {
        printf("%f, ",arr[l]);
    }
    
    for (int j = 0;j<n-1;j++) {
        for (int k = j+1;k<n;k++) {
            if(fabs(arr[j])>(fabs(arr[k]))) {
                trunggian = arr[j];
                arr[j] = arr[k];
                arr[k] = trunggian;
            }
        }
    }
    printf("\n\nDay giam dan theo gia tri tuyet doi la:");
    for (int l= 0;l<n;l++) {
        printf("%f, ",arr[l]);
    }
    return 0;
}