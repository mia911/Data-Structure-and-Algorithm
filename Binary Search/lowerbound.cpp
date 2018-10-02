#include <bits/stdc++.h>

using namespace std;

bool check(int x, int found) {
	if(x < found) {
		return false;
	} else {
		return true;
	}
}

int main() {
	bool debug;
	int n, found;
	cin >> n >> found;
	vector<int>arr(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int start = 0;
	int end = arr.size() - 1;
	int mid = 0;
	while(start < end) {
		if(debug) {
			cout << "1 start: " << start << " end: " << end << " mid: " << mid << endl;
		}
		mid = (start + end) / 2;
		if(check(mid, found)) {
			start = mid + 1;
		} else {
			end = mid;
		}
		if(debug) {
			cout << "2 start: " << start << " end: " << end << " mid: " << mid << endl;
		}
	}
	cout << start << endl;
	return 0;
}
