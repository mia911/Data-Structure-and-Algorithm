#include <iostream>

using namespace std;

int door_open(int n, int a, int m, long long d, int client[]) {
	int employee[n];
	int i;
	for(i = 0; i < n; i++) {
		employee[i] = (i + 1) * a;
		// cout<<employee[i]<<" ";
	}

	int people[m + n];
	int e = 0;
	int c = 0;
	for(i = 0; i < n + m; i++) {
		if(e == n || c == m)
			break;
		if(employee[e] < client[c]) {
			people[i] = employee[e];
			e += 1;
		} else {
			people[i] = client[c];
			c += 1;
		}
	}

	if(i != m + n) {
		if(e == n) {
			for(int j = i; j < m + n; j++) {
				people[j] = client[c];
				c += 1;
			}
		} else {
			for(int j = i; j < m + n; j++) {
				people[j] = employee[e];
				e += 1;
			}
		}
	}

	int open = 0;
	int count = 1;
	for(i = 1; i < n + m; i++) {
		if(people[i] - people[open] > d) {
			count += 1;
			open = i;
		}
	}
	return count;
}

int main () {
	int n, a, m;
	long long d;
	cin>>n;
	cin>>m;
	cin>>a;
	cin>>d;
	int client[m];
	for(int i = 0; i < m; i++)
		cin>>client[i];

	int output = door_open(n, a, m, d, client);
	cout<<output<<endl;
	return 0;
}
