#include <iostream>
#include <queue>

using namespace std;

void lienthong(int m, int n, int a[][100]) {
    queue<pair<int, int>>q;
    int cnt = 0;
    int visited[m][n];
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                pair<int, int>current = make_pair(i, j);
                q.push(current);
                while(q.size() > 0) {
                    pair<int, int>current = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        if(current.first + dx[k] >= 0 && current.first + dx[k] < m) {
                            if(current.second + dy[k] >= 0 && current.second + dy[k] < n) {
                                if(a[current.first + dx[k]][current.second + dy[k]] == 1 && visited[current.first + dx[k]][current.second + dy[k]] == 0) {
                                    q.push(make_pair(current.first + dx[k], current.second + dy[k]));
                                    visited[current.first + dx[k]][current.second + dy[k]] = 1;
                                }
                            }
                        }
                    }
                }
                cnt ++;
            }
        }
    }
    cout<<cnt<<endl;
    return;
}

int main(int argc, const char * argv[]) {
    int m, n;
    cin>>m;
    cin>>n;
    int a[100][100];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    lienthong(m, n, a);
    return 0;
}
