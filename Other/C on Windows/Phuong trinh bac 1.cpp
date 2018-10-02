#include <stdio.h>
#include <conio.h>
main() {
	//gia pt bac mot: ax = b
	int a, b;
	printf("Nhap vao 2 he so:");
	printf("a = ?"); 
	//gan input vao a
	scanf("%d",&a);
	printf ("b = ?"); scanf ("%d", &b);
	if(a==0) {
		if(b==0) {
			printf("pt co vo so nghiem");
		} else {
			printf("pt vo nghiem");
		}
	} else {
		printf("Pt co nghiem x = %d",b/a);
	}
}

