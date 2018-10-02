#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int>vertexes[], int vertex, int start) {
    int visited[vertex];
    for(int i = 0; i < vertex; i++)
        visited[i] = 0;
    visited[start] = 1;
    queue<int>q;
    q.push(start);
    while(q.size() > 0) {
        int u = q.front();
        q.pop();
        
        for(int i = 0; i < vertexes[u].size(); i++) {
            if(visited[vertexes[u][i]] == 0) {
                q.push(vertexes[u][i]);
                visited[vertexes[u][i]] = 1;
            }
        }
    }
}

void backtrack(vector<int>vertexes[], int vertex, int cur_vtx, int visited[]) {
    visited[cur_vtx] = 1;
    for(int i = 0; i < vertexes[cur_vtx].size(); i++) {
        if(vertexes[cur_vtx][i] == 0) {
            backtrack(vertexes, vertex, vertexes[cur_vtx][i], visited);
        }
    }
}

void DFS(vector<int>vertexes[], int vertex, int start) {
    int visited[vertex];
    for(int i = 0; i < vertex; i++)
        visited[i] = 0;
    backtrack(vertexes, vertex, start, visited);
    
}

int main(int argc, const char * argv[]) {
    int vertex;
    cin>>vertex;
    vector<int>vertexes[vertex + 1];
    int edge;
    cin>>edge;
    int a, b;
    for(int i = 0; i < edge; i++) {
        cin>>a;
        cin>>b;
        vertexes[a].push_back(b);
        vertexes[b].push_back(a);
    }
    BFS(vertexes, vertex, 0);
    return 0;
}














