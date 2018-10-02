#include <stdio.h>

int main () {
	float tong, hieu, tich, thuong, a, b;
	
	printf("Nhap 2 so a va b: \n");
	scanf("%f %f",&a,&b);
	
	tong = a+b;
	hieu = a-b;
	tich = a*b;
	if (b != 0) {
		thuong=a/b;
	} else {
		printf ("Khong thuc hien duoc phep chia");		
	}
	
	printf ("Tong 2 so la: %f",&tong);
	printf ("Hieu 2 so la: %f",&hieu);
	printf ("Tich 2 so la: %f",&tich);
	printf ("Thuong 2 so la: %f",&thuong);
	
	return 0;
	}
