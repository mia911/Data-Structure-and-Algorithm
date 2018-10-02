#include <stdio.h>
int main () {
	int N, i, array[100];
	int tang = 0;
	int tongtang = 0;
	int k;
	
	printf("Day co bao nhieu so hang?\n");
	scanf("%d",&N);
	
	printf("Nhap day so:\n");
	for(i=0; i<N; i++) {
		scanf("%d",&array[i]);
		}
	for(i=0; i<N-1;i++) {
	if(array[i]<array[i+1]){
		tang = 1;
		tongtang += tang;
	} else if (array[i]>array[i+1]){
		tang = 0;
		tongtang += tang;	
	}
}
	if(tongtang == (N-1)) {
		printf("day la day so tang");
	} else if (tongtang == 0) {
		printf("day la day so giam");
	} else {
		printf("day la day so khong tang khong giam");
	}
}
