#include <stdio.h>
#include <stdlib.h>

int main() {
	int a[2][3];
	int i;
	for (i=0; i<6; i++) {
		printf("\n Phan tu thu %d: ", i);
		scanf("%d", a+1);
	}
	int j;
	for (i=0; i<2; i++) {
		for (j=0; j<3; j++) {
			printf("%d", a[i]);
		}
	}
	return 0;
}