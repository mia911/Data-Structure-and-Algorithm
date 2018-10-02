#include <bits/stdc++.h>

using namespace std;

struct four
{
	int distance;
	int x;
	int y;
	int pass;

	four() {};
	four(int dd, int xx, int yy, int pp) { distance = dd; x = xx; y = yy; pass = pp; }

	bool operator < (const  four& temp) const {
        return distance > temp.distance;
	}
};

int m, n;
char road[100][100];
int k = 10;
int amount[1000];
int x_1, x_2, y_1, y_2;
//int visited[100][100][1024];
int dist[100][100][1024];

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
pair<int, int> trace[100][100];

string cvrt(int x) {
	string y;

	for(int i = 0; i < 10; i++) {
		y += '0';
	}

	for(int i = 0; i < 10; i++) {
		int remainer = x % 2;
		y[10 - i - 1] = remainer;
	}
	return y;
}

void findway() {
	dist[x_1][y_1][0] = 0;

	priority_queue<four> minDist;

	minDist.push(four(0, x_1, y_1, 0));

	while(1) {
		four temp = minDist.top();

		//cout<<temp.x<<" "<<temp.y<<endl;

		minDist.pop();

		if(temp.x == x_2 && temp.y == y_2) {
			break;
		}

		//visited[temp.x][temp.y][temp.pass] = 1;
		//cout << temp.distance << " " << temp.x << " " << temp.y << endl;
		//cout << dist[temp.x][temp.y][temp.pass] << endl;

		for(int i = 0; i < 4; i++) {
			four next;
			next.x = temp.x + dir_x[i];
			next.y = temp.y + dir_y[i];

			if(next.x < 0 || next.x >= m || next.y < 0 || next.y >= n)
				continue;

			string pass_or_not = cvrt(temp.pass);

			if(road[next.x][next.y] == '.') {
				next.pass = temp.pass;
			} else {
				for(int i = 0; i < 10; i++) {
					int z = road[next.x][next.y] - '0';
					if(z == i) {
						if(pass_or_not[z] == 0) {
							next.pass = temp.pass + (1<<(10 - i - 1));
						} else {
							next.pass = temp.pass;
						}
					}
				}
			}

			int c;

			if(next.pass == temp.pass) {
				c = 1;
			} else {
				c = amount[temp.pass];
			}

            if(dist[next.x][next.y][next.pass] > dist[temp.x][temp.y][temp.pass] + c) {
                dist[next.x][next.y][next.pass] = dist[temp.x][temp.y][temp.pass] + c;
                minDist.push(four(dist[next.x][next.y][next.pass], next.x, next.y, next.pass));
                trace[next.x][next.y] = make_pair(temp.x, temp.y);
                //cout << dist[temp.x][temp.y][temp.pass] << " " << dist[next.x][next.y][next.pass] << " " << next.x << " " << next.y << endl;
            }
		}
	}

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

    x_1 -= 1;
    y_1 -= 1;
    x_2 -= 1;
    y_2 -= 1;

	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			for(int k = 0; k < 1024; k++) {
				dist[i][j][k] = INT_MAX;
			}
		}
	}

	findway();

	int a = INT_MAX;

	for(int i = 0; i < 1024; i++) {

        if(a > dist[x_2][y_2][i]) {
            a = dist[x_2][y_2][i];
        }
	}
	cout << a << endl;

	pair<int, int> temp;

	while(temp.first != x1 && temp.second != y1) {
		temp.first = trace[x2][y2].first;
		temp.second = trace[x2][y2].second;
		cout << temp.first << " " << temp.second << endl;
		x2 = temp.first; 
		y2 = temp.second;
	}
	return 0;
}






