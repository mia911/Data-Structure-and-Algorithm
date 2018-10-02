#include <bits/stdc++ .h>
using namespace std;

const bool debug = true;
const int MAX_N = 100000;

int n;
int a[MAX_N + 2];

int main() {
	ifstream cin("debug.inp");
	//ofstream cout("debug.out");
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if(debug) {
		cout << "n = " << n << "\n";
		cout << "a[] = ";
		for(int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}

	sort(a, a + n);

	if(debug) {
		cout << "a[] = ";
		for(int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}