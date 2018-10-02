#include <bits/stdc++.h>

using namespace std;

int navigate_i[4] = {1, -1, 0, 0};
int navigate_j[4] = {0, 0, -1, 1};
char way[1000][1000];
int visited[1000][1000][4];
int turn[1000][1000][4];
int flag = 0;

void minTurnDir(int n, int m, int &x, int &y, int &dir1) {
	int minTurn = INT_MAX;

	for(int k = 0; k < n; k++) {
		for(int l = 0; l < m; l++) {
			for(int i = 0; i < 4; i++) {
				if(turn[k][l][i] < minTurn && visited[k][l][i] == 0) {
					minTurn = turn[k][l][i];
					x = k;
					y = l;
					dir1 = i;
				}
			}
		}
	}

	return;
}

void search(int n, int m, int i, int j) {
	for(int k = 0; k < 4; k++) {
		turn[i][j][k] = 0;
	}

	for(int z = 0; z < n*m; z++) {
		int x = -1;
		int y = -1;
		int dir1 = -1;
		minTurnDir(n, m, x, y, dir1);

		if(x == -1)
			continue;

		visited[x][y][dir1] = 1;

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

			if(turn[newi][newj][k] > turn[x][y][dir1] + c)
				turn[newi][newj][k] = turn[x][y][dir1] + c;
		}
	}
	return;
}

void waytowork(int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int l = 0; l < 4; l++) {
				visited[i][j][l] = 0;
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
        cout<<"No"<<endl;
	return 0;
}
