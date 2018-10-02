#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
const int INF = (int)(1e9);

int n, m;
vector<int> adj[MAXN];
int start, goal;

void init_graph() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> start >> goal;
}

int min_dist[MAXN];

void dijkstra(int start, int goal) {
    for(int i = 1; i <= n; ++i) min_dist[i] = INF;
    min_dist[start] = 0;

    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > heap_min;
    heap_min.push(make_pair(min_dist[start], start));
    while (heap_min.size() > 0) {
        pair<int, int> top_heap = heap_min.top();
        int u = top_heap.second, min_dist_u = top_heap.first;

        if (u == goal) break;

        if (min_dist[u] != min_dist_u) continue;

        for(int v : adj[u]) {
            if (min_dist[v] > min_dist[u] + 1) {
                min_dist[v] = min_dist[u] + 1;
                heap_min.push(make_pair(min_dist[v], v));
            }
        }
    }

    cout << "min dist from " << start << " to " << goal << " is " << min_dist[goal] << "\n";
}

int main() {
    init_graph();
    dijkstra(start, goal);
}
