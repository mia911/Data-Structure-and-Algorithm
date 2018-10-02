#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p[10];
	int i;
	for (i=0; i<10; i++) {
		p[i] = (int *) calloc(5, sizeof(int));
	}

	for (i=0; i<10; i++) {
		free(p[i]);
		printf("\n p[%d] co dia chi: %p", i, p[i]);
	}
}