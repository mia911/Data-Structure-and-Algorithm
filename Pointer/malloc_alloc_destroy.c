#include <stdio.h>
#include <stdlib.h>

int main() {
	int *px;
	px = malloc(sizeof(int));
	*px = 123;

	printf("Vi tri cua con tro px: %p\n", px);
	printf("Gia tri cua px: %d\n", *px);
	return 0;
}