#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> >&graph, vector<int>&visited, int cur_vtx) {
	cout << cur_vtx;
	visited[cur_vtx] = 1;
	for(int i = 0; i < graph[cur_vtx].size(); i++) {
		if(graph[cur_vtx][i] == 0) {
            dfs(graph, visited, graph[cur_vtx][i]);
		}
	}
	return;
}

int main () {
	int vertices, edges, a, b;
	cout << "Input vertices: ";
	cin >> vertices;
	cout << "Input edges: ";
	cin >> edges;

	vector<vector<int>>graph(vertices);
	for(int i = 0; i < edges; i++) {
		cout << "Input an edge: ";
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int>visited(vertices, 0);
	dfs(graph, visited, 0);
	return 0;
}
