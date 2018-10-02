#include <stdio.h>
#include <stdlib.h>

typedef char Ho_Ten[20];
Ho_Ten *p[10];

main() {
	int i;
	for (i=0; i<10; i++) {
		p[i] = malloc(sizeof(Ho_Ten));
		printf("Nhap ten cua %d", i);
		gets(*p[i]);
	}

	pritnf("In ket qua:\n");
	for (i=0; i<10; i++) {
		printf("Nguoi thu %d la: %s", i, *p[i]);
	}
}
