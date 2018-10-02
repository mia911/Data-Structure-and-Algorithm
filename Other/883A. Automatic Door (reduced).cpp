#include <iostream>
#include <cmath>

using namespace std;

int door_open(int n, int a, int m, long long d, long long client[]) {
	int j = 1;
	int c = 0;
	long long open;
	long long employee;
	long long count = 1;

	if(a < client[0]) {
		open = a;
		j += 1;
	} else {
		open = client[0];
		c += 1;
	}

	while(j <= n && c < m) {
		employee = j * a;
		if(employee < client[c]) {
			if(employee - open > d) {
				open = employee;
//				cout<<open<<" ";
				count += 1;
			}
			j += 1;
		} else {
			if(client[c] - open > d) {
				open = client[c];
//				cout<<open<<" ";
				count += 1;
			}
			c += 1;
		}
	}

	if(j <= n || c < m) {
		if(j <= n) {
		    int flag = 0;
            while(j <= n) {
                employee = j * a;
                if(employee - open > d) {
                    flag = 1;
                    break;
                } else
                    j++;
            }
            if(flag == 1) {
                int last_emp = a*n - ((a*n - a*j) % ((a - (d % a)) + d));
                if(d < a) {
                    int last_n = last_emp / a;
                    count += last_n - j + 1;
                } else {
                    count += (last_emp - a*j) / ((a - (d % a)) + d) + 1;
                }
            }
		} else if (c < m) {
			for(int i = c; i < m; i++) {
				if(client[i] - open > d) {
					open = client[i];
					count += 1;
				}
			}
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
	long long client[m];
	for(int i = 0; i < m; i++)
		cin>>client[i];

	int output = door_open(n, a, m, d, client);
	cout<<output<<endl;
	return 0;
}
