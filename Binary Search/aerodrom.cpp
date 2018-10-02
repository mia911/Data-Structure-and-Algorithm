#include <bits/stdc++.h>

using namespace std;

bool check(long long mid, int people, vector<int>& tTable) {
	long long tPeople = 0;
	for(int i = 0; i < tTable.size(); i++) {
		tPeople += mid / tTable[i];
	}
	if(tPeople >= people) {
		return true;
	} else {
		return false;
	}
}

int main() {
	bool debug = false;
	int nTable, nPeople;
	cin >> nTable >> nPeople;
	vector<int> tTable(nTable, 0);
	long long maxTime = 0;
	for(int i = 0; i < nTable; i++) {
		cin >> tTable[i];
		if(tTable[i] > maxTime) {
			maxTime = tTable[i];
		}
	}

	maxTime *= nPeople;
	long long startTime = 0;
	long long mid = 0;
	while(startTime < maxTime) {
		if(debug) {
			cout << "startTime: " << startTime << " maxTime: " << maxTime << " mid: " << mid << endl;
		}
		mid = (startTime + maxTime) / 2;
		if(check(mid, nPeople, tTable)) {
			maxTime = mid;
		} else {
			startTime = mid + 1;
		}
		if(debug) {
			cout << "startTime: " << startTime << " maxTime: " << maxTime << " mid: " << mid << endl;
		}
	}

	cout << startTime << endl;
	return 0;
}
