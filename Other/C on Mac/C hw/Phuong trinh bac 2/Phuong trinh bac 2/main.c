#include <stdio.h>
#include <math.h>
int main() {
    float a,b,c;
    float x1, x2;
    scanf("%f %f %f",&a,&b,&c);
    if (a==0) {
        if (b==0) {
            if (c==0) {
                printf("Phương trinh co vo so nghiem\n");
            } else {
                printf("Phuong trinh vo nghiem\n");
            }
        } else {
            printf("Phuong trinh co 1 nghiem: %f\n",(-c/b));
        }
    } else {
        float delta=pow(b,2)-(4*a*c);
        float candelta = sqrt(fabs(delta));
        float thuc = -b/2*a;
        float ao = candelta/2*a;
        if (delta>0) {
            x1 = thuc + ao;
            x2 = thuc- ao;
            printf("x1 = %f\n",x1);
            printf("x2 = %f\n",x2);
        } else if (delta==0) {
            x1 = x2 = thuc;
            printf("x1 = x2 = %f\n",x1);
        } else if (delta<0) {
            printf("x1 = %f + i*%f\n",thuc, ao);
            printf("x2 = %f + i*%f\n",thuc, ao);
        }
    }
    return 0;
}