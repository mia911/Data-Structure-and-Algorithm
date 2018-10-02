#include <stdio.h>

int main(){
    int a, b;
    printf("\n Nhap gia tri dau vao la cac so nguyen duong");
    printf("\n a = "); scanf("%d",&a);
    printf("\n b = "); scanf("%d",&b);
    int A = a, B = b;
    
    //Dung giai thuat Euclid tim UCLN
    int c;
    do{
        c = a-b;
        if(c<0){
            b=-c;
        }else if(c>0){
            a=c;
        }
    }while(c!=0);
    
    printf("\n UCLN( %d, %d ) = %d", A, B, a);
    printf("\n BCNN( %d, %d ) = %d\n", A, B, A*B/a);
    
    return 0;
}