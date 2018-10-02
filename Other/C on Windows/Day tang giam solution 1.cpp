#include <stdio.h>

using namespace std;

int main() {
	int N;
	int arr[100];
	bool tang = true;
	bool giam = true;
	
	printf("Nhap N:\n");
	scanf("%d", &N);
	
	printf("Nhap day:\n");
	for (int i = 0; i<N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] < arr[i-1]) {
			tang = false;
		} else if (arr[i] > arr[i-1]) {
			giam = false;	
		}
	}
	if (tang && !giam) {
		printf("Tang");
	} else if (!tang && giam) {
		printf("Giam");
	} else {
		printf("KHong tang khong giam");
	}
	return 0;
}
