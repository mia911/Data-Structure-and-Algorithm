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

struct state {
    int x, y, dir, turn;
    state(int _x, int _y, int _dir, int _turn) {
        x = _x; y = _y; dir = _dir; turn = _turn;
    }

    bool operator < (const state &other) const {
        return turn > other.turn;
    }
};

void solve() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int dir = 0; dir < 4; ++dir) {
                min_turn[i][j][dir] = INF;
            }

    priority_queue< state, vector<state> > q;
    for(int dir = 0; dir < 4; ++dir) {
        min_turn[sx][sy][dir] = 0;
        q.push(state(sx, sy, dir, min_turn[sx][sy][dir]));
    }

    while (!q.empty()) {
        state s = q.top();
        q.pop();
        int x = s.x, y = s.y, dir1 = s.dir;
        if (min_turn[x][y][dir1] != s.turn) continue;

        for(int dir2 = 0; dir2 < 4; ++dir2) {
            int u = x + d_row[dir2], v = y + d_col[dir2];
            if ((1 <= u) && (u <= n) && (1 <= v) && (v <= m) && (grid[u][v] != '*')) {
                if (min_turn[u][v][dir2] > min_turn[x][y][dir1] + (dir1 != dir2)) {
                    min_turn[u][v][dir2] = min_turn[x][y][dir1] + (dir1 != dir2);
                    q.push(state(u, v, dir2, min_turn[u][v][dir2]));
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
    //freopen("input.txt", "r", stdin);

    read_input();
    solve();
}
