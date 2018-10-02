#include <bits/stdc++.h>
using namespace std;

int squareRoot(int a) {
	int res = 0;
	while((res + 1) * (res + 1) <= a) {
		int i = 1;
		while((res + i) * (res + i) <= a) {
			i *= 2;
		}
		res += i / 2;
	}
	return res;
}

int main() {
	int a;
	cin >> a;
	cout << squareRoot(a) << endl;
	return 0;
}