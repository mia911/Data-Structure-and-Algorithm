#include <stdio.h>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int arr[N];
	bool tang = true;
	bool giam = true;
	scanf("%d", &arr[0]);
	for (int i = 1; i<N; i++) {
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
		printf("Khong tang khong giam");
	}
	return 0;
}
