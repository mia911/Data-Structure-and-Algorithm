#include <stdio.h>
#include <conio.h>
main() {
	int p;
	printf("Nhap gia tri cua p = ");
	scanf ("%d", &p);
	int flag = 1;
	
	if (p <= 1) {
		printf("p ko la so nguyen to");
	} else {
	for(int i = 2;i <= p-1; i++){
		if (p%i==0) {
			flag = 0;
			break;
		} 
	}
	if(flag ==1){
		printf("p = %d la so nguyen to",p);
	} else {
		printf("p %d ko la so nguyen to",p);
	}
}
}

