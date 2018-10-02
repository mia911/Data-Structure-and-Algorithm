#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

int visited[100];
int cnt = 0;
int cnt_dfs = 0;
vector<int>visit[10];
vector<int>visit_dfs[10];

void BFS(vector<int>vertex[], int n_vertex, int start) {
    int trace[n_vertex];
    queue<int>q;
    q.push(start);
    visited[start] = 1;

    while(q.size() > 0) {
        int x = q.front();
        visit[cnt].push_back(x);
        q.pop();
    
        for(int i = 0; i < vertex[x].size(); i++) {
            if(visited[vertex[x][i]] == 0) {
                q.push(vertex[x][i]);
                trace[vertex[x][i]] = x;
                visited[vertex[x][i]] = 1;
            }
        }
    }
    
    cnt ++;
    return;
}

void backtrack(vector<int>vertex[], int n_vertex, int start) {
    visited[start] = 1;
    visit_dfs[cnt_dfs].push_back(start);
    for(int i = 0; i < vertex[start].size(); i++) {
        if(visited[vertex[start][i]] == 0) {
            backtrack(vertex, n_vertex, vertex[start][i]);
        }
    }
}

void DFS(vector<int>vertex[], int n_vertex) {
    for(int i = 0; i < n_vertex; i++) {
        visited[i] = 0;
    }
    
    for(int i = 0; i < n_vertex; i++) {
        if(visited[i] == 0) {
            backtrack(vertex, n_vertex, i);
            cnt_dfs ++;
        }
    }
    cout<<cnt_dfs<<endl;
    for(int i = 0; i < cnt_dfs; i++) {
        for(int j = 0; j < visit_dfs[i].size(); j++) {
            cout<<visit_dfs[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}

int main () {
    int n_vertex;
    cin>>n_vertex;
    vector<int>vertex[n_vertex];
    int n_edge;
    cin>>n_edge;
    int a, b;
    for(int i = 0; i < n_edge; i++) {
        cin>>a;
        cin>>b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }
    
    for(int i = 0; i < n_vertex; i++) {
        if(visited[i] == 0) {
            BFS(vertex, n_vertex, i);
        }
    }

    cout<<cnt<<endl;
    for(int i = 0; i < cnt; i++) {
        for(int j = 0; j < visit[i].size(); j++) {
            cout<<visit[i][j]<<" ";
        }
        cout<<"\n";
    }
    DFS(vertex, n_vertex);
    return 0;
}
