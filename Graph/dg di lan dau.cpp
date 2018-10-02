#include <bits/stdc++.h>

using namespace std;

int m, n;
char road[1000][1000];
int k = 10;
int amount[1000];
int x_1, x_2, y_1, y_2;
int visited[1000][1000];
int dist[1000][1000];

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

void findway() {
	dist[x_1][x_2] = 0;

	priority_queue<pair<int, int> > minDist;

	minDist.push(make_pair(x_1, y_1));

	while(1) {
		pair<int, int> temp = minDist.top();
		minDist.pop();

		if(temp.first == x_2 && temp.second == y_2)
			break;

		visited[x_1][x_2] = 1;

		for(int i = 0; i < 4; i++) {
			int x = temp.first + dir_x[i];
			int y = temp.second + dir_y[i];

			if(x < 0 || x >= m || y < 0 || y >= n) {
				continue;
			}

			if(road[x][y] != '.' && visited[x][y] == 0) {
				dist[x][y] = min(dist[temp.first][temp.second] + amount[road[x][y] - '0'], dist[x][y]);
			} else {
				dist[x][y] = min(dist[temp.first][temp.second] + 1, dist[x][y]);
			}
			minDist.push(make_pair(x, y));
		}
	}

	cout<<dist[x_2][y_2]<<endl;
	return;
}

int main () {
	freopen("input.txt", "r", stdin);

	cin>>m; cin>>n;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin>>road[i][j];
		}
	}

	for(int i = 0; i < k; i++) {
		cin>>amount[i];
	}

	cin>>x_1; cin>>y_1; cin>>x_2; cin>>y_2;

	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < 1000; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	findway();
	return 0;
}
