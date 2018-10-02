

#include <stdio.h>

int main() {
    int n,i;
    int soam = 0;
    int so0 = 0;
    float arr[1024];
    float tongam = 0;
    float tongduong = 0;
    float y;
    do {
        printf("Nhap day so:");
        scanf("%f",&y);
        arr[i] = y;
        i++;
        n++;
    } while (n<9);
    
    for (int l = 0;l<n;l++) {
        printf("%f, ",arr[l]);
    }
    
    for (int j = 0; j<n; j++) {
        if (arr[j]<0) {
            tongam += arr[j];
            soam++;
        } else if (arr[j] == 0) {
                so0++;
        } else {
            tongduong += arr[j];
        }
    }
    
    float trungbinham;
    trungbinham = tongam/soam;
    printf("\nTrung binh cac so am la: %f\n",trungbinham);
    printf("Tong cac so duong la: %f\n",tongduong);
    printf("So cac so 0 trong day la: %d\n",so0);
    
    float x;
    printf("Nhap so x:");
    scanf("%f",&x);
    for (int k = 0; k<n;k++) {
        if (x==arr[k]) {
            printf("So can tim nam o vi tri:%d\n",k);
        }
    }
    return 0;
}
