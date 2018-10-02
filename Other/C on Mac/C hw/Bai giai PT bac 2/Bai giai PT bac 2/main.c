#include <stdio.h>
#include <math.h>
int main(){
    float a, b, c;
    printf("\n Nhap cac so dau vao");
    printf("\n a = "); scanf("%f",&a);
    printf("\n b = "); scanf("%f",&b);
    printf("\n c = "); scanf("%f",&c);
    
    if(a==0){
        if(b==0){
            if(c==0){
                printf("\n => KL: Phuong trinh co vo so nghiem");
            }else{
                printf("\n => KL: Phuong trinh vo nghiem");
            }
        }else{
            printf("\n => KL: Phuong trinh co 1 nghiem: %f",c/b);
        }
    }else{
        float delta = b*b-4*a*c;
        float can_delta = sqrt(fabs(delta));
        float thuc = -b/(2*a);
        float ao = can_delta/(2*a);
        
        if(delta<0){
            printf("\n => KL: Phuong trinh co 2 nghiem phuc:");
            printf("\n\t x_1 = %f + i* %f ", thuc, fabs(ao));
            printf("\n\t x_2 = %f - i* %f ", thuc, fabs(ao));
        }else if(delta==0){
            printf("\n => KL: Phuong trinh co nghiem kep: x = %f ",thuc);
        }else{
            printf("\n => KL: Phuong trinh co 2 nghiem thuc: ");
            printf("\n\t x_1 = %f ", thuc+ao);
            printf("\n\t x_2 = %f ", thuc-ao);
        }
    }
    
    return 0;
}