#include <stdio.h>
#include <string.h>

typedef struct bohoso {
    char hoten[40];
    float diem;
    char loai[40];
} Hoso;

int main() {
    int n;
    printf("So hoc sinh se duoc nhap vao: ");
    scanf("%d",&n);
    
    Hoso bohoso[n];
    for (int i = 0; i<n; i++) {
        printf("Nhap ho ten hoc sinh: ");
        scanf("%99s",bohoso[i].hoten);
        
        printf("Nhap diem: ");
        scanf("%f", &bohoso[i].diem);
        
        if(bohoso[i].diem == 9 || bohoso[i].diem == 10) {
            strcpy(bohoso[i].loai,"Gioi");
        } else if (bohoso[i].diem == 8 || bohoso[i].diem == 7) {
            strcpy(bohoso[i].loai,"Kha");
        } else if (bohoso[i].diem == 6 || bohoso[i].diem == 5) {
            strcpy(bohoso[i].loai,"Trung binh");
        } else {
            strcpy(bohoso[i].loai,"Khong Dat");
        }
        
    }
    
    for (int j = 0; j<n; j++) {
        printf("%s %f %s\n", bohoso[j].hoten,bohoso[j].diem,bohoso[j].loai);
    }
    return 0;
}

