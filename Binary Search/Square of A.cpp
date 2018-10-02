#include <bits/stdc++.h>

using namespace std;

int main () {
	int a;
	bool debug = false;
	cin >> a;
	if(a == 0) {
		cout << 0 << endl;
		return 0;
	}
	if(a == 1) {
		cout << 1 << endl;
		return 0;
	}
	int i = 1;
	int tmp = 0;
	int res = (tmp + i) * (tmp + i);
	while(true) {
        if(debug) {
            cout << 1 << " i: " << i << " tmp: " << tmp << " res: " << res << endl;
        }
		i *= 2;
		res = (tmp + i) * (tmp + i);
		if(debug) {
            cout << 2 << " i: " << i << " tmp: " << tmp << " res: " << res << endl;
        }
		if(res > a) {
			i /= 2;
			tmp += i;
			i = 1;
			res = (tmp + i) * (tmp + i);
			if(debug) {
                cout << 3 << " i: " << i << " tmp: " << tmp << " res: " << res << endl;
            }
			if(res > a) {
				break;
			}
		}
	}
	cout << tmp << " " << (int)sqrt(a) << endl;
	return 0;
}
