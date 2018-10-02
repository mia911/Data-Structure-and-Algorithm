#include <iostream>

using namespace std;

string a, b;
int flag[100][100];
int track[100][100];

void lcs() {
	int n = a.length();
	int m = b.length();
	if(n == 0 || m == 0)
		cout<<0<<"\n";
		return;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i - 1] == b[j - 1]) {
				flag[i][j] = flag[i - 1][j - 1] + 1;
				track[i][j] = 0;
			} else {
				if(flag[i][j - 1] > flag[i - 1][j]) {
					flag[i][j] = flag[i][j - 1];
					track[i][j] = 1;
				} else {
					flag[i][j] = flag[i - 1][j];
					track[i][j] = 2;
				}
			}
		}
	}

	// int idx = flag[a.length()][b.length()];
	// string c[idx];
	// while(n > 0 || m > 0) {
	// 	if(track[n][m] == 0) {
	// 		c[idx - 1] = a[n];
	// 		idx -= 1;
	// 		n -= 1;
	// 		m -= 1;
	// 	} else if(track[n][m] == 1) {
	// 		m -= 1;
	// 	} else {
	// 		n -= 1;
	// 	}
	// }
	// cout<<c<<"\n";
	cout<<flag[a.length()][b.length()]<<"\n";
	return;
}

int main () {
	cout<<"Input string a: "; cin>>a;
	cout<<"Input string b: "; cin>>b;
	lcs();
	return 0;
}














