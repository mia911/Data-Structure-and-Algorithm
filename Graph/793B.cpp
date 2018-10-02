#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
const int MAXM = 1000 + 10;
const int INF = (int)(1e9);

int n, m;
char grid[MAXN][MAXM];
int sx, sy, fx, fy;

void read_input() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                sx = i; sy = j;
            }
            if (grid[i][j] == 'T') {
                fx = i; fy = j;
            }
        }
}

int d_row[] = {-1, 1, 0, 0};
int d_col[] = {0, 0, 1, -1};

int min_turn[MAXN][MAXM][4];
bool marked[MAXN][MAXM][4];

void find_min(int &x, int &y, int &dir) {
    int min_val = INF;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int d = 0; d < 4; ++d)
                if ((!marked[i][j][d]) && (min_turn[i][j][d] < min_val)) {
                    min_val = min_turn[i][j][d];
                    x = i; y = j; dir = d;
                }
}

void solve() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int dir = 0; dir < 4; ++dir) {
                min_turn[i][j][dir] = INF;
                marked[i][j][dir] = false;
            }
    for(int dir = 0; dir < 4; ++dir) min_turn[sx][sy][dir] = 0;
    while (true) {
        int x = -1, y = -1, dir1 = -1;
        find_min(x, y, dir1);
        if (x == -1) break; //done dijkstra

        marked[x][y][dir1] = true;

        for(int dir2 = 0; dir2 < 4; ++dir2) {
            int u = x + d_row[dir2], v = y + d_col[dir2];
            if ((1 <= u) && (u <= n) && (1 <= v) && (v <= m) && (grid[u][v] != '*')) {
                if (min_turn[u][v][dir2] > min_turn[x][y][dir1] + (dir1 != dir2)) {
                    min_turn[u][v][dir2] = min_turn[x][y][dir1] + (dir1 != dir2);
                }
            }
        }
    }

    int max_turn_allowed = 2;
    bool yes = false;
    for(int dir = 0; dir < 4; ++dir) {
        if (min_turn[fx][fy][dir] <= max_turn_allowed) {
            yes = true;
            break;
        }
    }

    if (yes) cout << "YES"; else cout << "NO";
}

int main() {
    freopen("input.txt", "r", stdin);

    read_input();
    solve();
}
