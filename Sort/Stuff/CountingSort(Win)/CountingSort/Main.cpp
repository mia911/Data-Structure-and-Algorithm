#include <stdio.h>
#include "Header.h"

int main() {
	int a[10] = { 1, 5, 6 ,7, 9 ,7, 5 ,2, 1 ,5 };
	CountingSort(a, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}