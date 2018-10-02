#include <bits/stdc++.h>

using namespace std;

bool check(int m, int n) {
	return (long long)m * m <= n;
}

int main() {
	bool debug = false;
	int n;
	cin >> n;
	int start = 0;
	int end = n;
	int m = 0;
	while(start < end) {
		if(debug) {
			cout << "1 start: " << start << " end: " << end << " m: " << m << endl;
		}
		m = (start + end + 1) / 2;
		if(!check(m, n)) {
			end = m - 1;
		} else {
			start = m;
		}	
		if(debug) {
			cout << "2 start: " << start << " end: " << end << " m: " << m << endl;
		}
	}

	cout << start << endl;
	return 0;
}