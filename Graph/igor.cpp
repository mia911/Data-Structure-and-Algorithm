#include <bits/stdc++.h>

using namespace std;

int n, m;
char road[1000][1000];
int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, -1, 1};
int visited[1000][1000];
int direction = 0;
int new_direction;
int turn = 0;
int flag = 0;

int canmove(int a, int i, int j) {
	int newmovex = move_x[a] + i;
	int newmovey = move_y[a] + j;

	if(newmovex >= n || newmovey >= m || newmovex < 0 || newmovey < 0)
		return 0;
	if(road[newmovex][newmovey] == '*')
		return 0;

	return 1;
}


void recursive(int i, int j, int direction) {
	if(flag == 1 || turn > 2)
		return;

	if(road[i][j] == 'T') {
		if(turn <= 2) {
			cout<<"YES";
			flag = 1;
			return;
		}
	}

	int oldturn = turn;
	for(int a = 0; a < 4; a++) {
		turn = oldturn;
		if(a == 0)
			new_direction = 1;
		else if(a == 1)
			new_direction = 2;
		else if(a == 2)
			new_direction = 3;
		else
			new_direction = 4;

		if(canmove(a, i, j)) {
			if(new_direction != direction && direction != 0) {
				turn ++;
			}

			if(visited[i + move_x[a]][j + move_y[a]] < turn)
				continue;
			
			visited[i + move_x[a]][j + move_y[a]] = turn;
			recursive(i + move_x[a], j + move_y[a], new_direction);
		}
	}
	return;
}

void waytowork() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			visited[i][j] = 3;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(road[i][j] == 'S')
				recursive(i, j, direction);
		}
	}
	return;
}

int main () {
	cin>>n;
	cin>>m;
	char temp;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin>>temp;
			road[i][j] = temp;
		}
	}
	waytowork();
	if(flag == 0)
        cout<<"NO";
	return 0;
}
