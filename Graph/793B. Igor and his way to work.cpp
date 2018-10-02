#include <iostream>

using namespace std;

int navigate_i[4] = {1, -1, 0, 0};
int navigate_j[4] = {0, 0, -1, 1};
char way[1000][1000];
int visited[1000][1000][3][5];

int flag = 0;

void recursive_way(int n, int m, int i, int j, int turn, int direction) {
	if(flag == 1)
		return;

	if(i >= n || j >= m || i < 0 || j < 0) {
		return;
	}

	if (turn > 2) {
  		return; // not care
  	}
  	// => turn <= 2, direction <= 4 => visited size = n * m * 2 * 4
  	if (visited[i][j][turn][direction] == 1) {
  		return;
  	}

  	visited[i][j][turn][direction] = 1;

	if(way[i][j] == '*') {
		return;
	} else if(way[i][j] == 'T') {
		if(turn <= 2) {
			cout<<"YES";
			flag = 1;
			return;
		}
	} else {
		for(int k = 0; k < 4; k++) {
			int next_turn = turn;
			int next_direction = direction;
			if(k == 0) {
				if(direction != 1 && direction != 0) {
					next_turn += 1;
				}
				next_direction = 1;
			} else if(k == 1) {
				if(direction != 2 && direction != 0) {
					next_turn += 1;
				}
				next_direction = 2;
			} else if(k == 2) {
				if(direction != 3 && direction != 0) {
					next_turn += 1;
				}
				next_direction = 3;
			} else {
				if(direction != 4 && direction != 0) {
					next_turn += 1;
				}
				next_direction = 4;
			}
			recursive_way(n, m, i + navigate_i[k], j + navigate_j[k], next_turn, next_direction);
		}
	}
	return;
}

void waytowork(int n, int m) {
	int turn = 0;
	int direction = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(way[i][j] == 'S') {
				recursive_way(n, m, i, j, turn, direction);
				break;
			}
		}
	}
	if(flag == 0) {
		cout<<"NO";
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
	return 0;
}
