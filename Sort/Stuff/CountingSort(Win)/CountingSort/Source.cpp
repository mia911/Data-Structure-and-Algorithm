#include "Header.h"

void CountingSort(int *a, int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (k < a[i]) {
			k = a[i];
		}
	}

	int b[n], c[k], i, j;
	
	for (i = 0; i < k; i++) {
		c[i] = 0;
	}

	for (j = 0; j < n; j++) {
		c[a[j]] = c[a[j]] + 1;
	}

	for (i = 1; i < k; i++) {
		c[i] = c[i] + c[i - 1];
	}

	for (j = n - 1; j >= 0; j--) {
		b[c[a[j]]] = a[j];
		c[a[j]] = c[a[j]] - 1;
	}
}