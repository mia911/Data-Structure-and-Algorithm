#include <bits/stdc++.h>

using namespace std;

int navigate_i[4] = {1, -1, 0, 0};
int navigate_j[4] = {0, 0, -1, 1};
char way[1000][1000];
int turn[1000][1000][4];
int flag = 0;

struct state {
	int x, y, dir, turn;
	state(int _x, int _y, int _dir, int _turn) {
		x = _x; y = _y; dir = _dir; turn = _turn;
	}

	bool operator < (const state &other) const {
		return turn > other.turn;
	}
};

void search(int n, int m, int i, int j) {
	priority_queue< state, vector<state> > q;
	for(int k = 0; k < 4; k++) {
		turn[i][j][k] = 0;
		q.push(state(i, j, k, turn[i][j][k]));
	}

	while(!q.empty()) {
		state s = q.top();
		q.pop();
		int x = s.x, y = s.y, dir1 = s.dir;
		if(turn[x][y][dir1] != s.turn) continue;

		if(turn[x][y][dir1] > 2)
			continue;

		if(way[x][y] == '*') {
			continue;
		} else if(way[x][y] == 'T') {
			if(turn[x][y][dir1] <= 2) {
				cout<<"YES";
				flag = 1;
				return;
			}
		}

		for(int k = 0; k < 4; k++) {
			int newi = x + navigate_i[k];
			int newj = y + navigate_j[k];

			if(newi >= n || newj >= m || newi < 0 || newj < 0)
				continue;

			int c = k == dir1 ? 0 : 1;

			if(turn[newi][newj][k] > turn[x][y][dir1] + c) {
				turn[newi][newj][k] = turn[x][y][dir1] + c;
				q.push(state(newi, newj, k, turn[newi][newj][k]));
			}
			
		}
	}
	return;
}

void waytowork(int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int l = 0; l < 4; l++) {
				turn[i][j][l] = INT_MAX;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(way[i][j] == 'S') {
				search(n, m, i, j);
				break;
			}
		}
	}

	return;
}

int main () {
	int n, m;
	cin>>n;
	cin>>m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>way[i][j];
		}
	}
	waytowork(n, m);

	if (flag == 0)
        cout<<"NO"<<endl;
	return 0;
}
