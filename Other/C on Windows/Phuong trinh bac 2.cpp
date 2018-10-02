#include <stdio.h>
#include <conio.h>
#include<math.h>

main() {
	float a, b, c;
	float d, x1, x2;
	
	printf("Nhap 3 so a,b,c");
	scanf ("%f%f%f",&a,&b,&c);
	
	d = b*b - (4*a*c);
	
	if (d < 0) {
		printf ("Phuong trinh vo nghiem");
		return 0;
	} else if (d == 0) {
		printf ("Phuong trinh co nghiem kep:");
		x1 = -b/(2*a);
		x2 = -b/(2*a);
		printf("Nghiem cua phuong trinh la:");
		printf("%.3f,%.3f",x1, x2);
		return 0;
	} else if (d > 0) {
		printf ("Phuong trinh co 2 nghiem phan biet");
		x1 = ( -b + sqrt(d)) / (2* a);
   		x2 = ( -b - sqrt(d)) / (2* a);
   		printf("Nghiem cua phuong trinh la:");
		printf("%.3f,%.3f",x1, x2);
		return 0;
	}
}
		
		
		
		
	
