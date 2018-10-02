#include <stdio.h>

int main()
{
    int array[100], N, i, maximum;
    
    printf("Day se co bao nhieu so?\n");
    scanf ("%d", &N);
    
    printf("Nhap cac so trong day:\n");
    for (i = 0; i<N; i++) {
        scanf("%d",&array[i]);
    }
    
    for (i = 0; i<N; i++) {
        if (array[i] < 0) {
            array[i] = array[i] * (-1);
            scanf("%d",&array[i]);
        }
    }
    
    maximum = array[0];
    
    for (i = 1; i<N; i++) {
        if (array[i] > maximum) {
            maximum =array[i];
        }
    }
     printf("Gia tri lon nhat cua day la: %d",&maximum);
    return 0;
}

