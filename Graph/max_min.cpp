#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

int BFS(vector<pair<int, int>>vertexes[], int vertex, int srt, int fin, int mid) {
    int visited[vertex], x, flag = 0;
    queue<int>q;
    pair<int, int>tmp;
    
    for(int i = 0; i < vertex; i++)
        visited[i] = 0;
    
    q.push(srt);
    visited[srt] = 1;
    
    while(q.size() > 0) {
        x = q.front();
        q.pop();
        for(int i = 0; i < vertexes[x].size(); i++) {
            tmp = vertexes[x][i];
            if(tmp.second >= mid) {
                if(visited[tmp.first] == 0 && tmp.first != fin) {
                    q.push(tmp.first);
                } else if(tmp.first == fin) {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            break;
    }
    
    if(flag == 1)
        return 1;
    return 0;
}

int binarysearch(vector<pair<int, int>>vertexes[], int vertex, int srt, int fin, int beg, int end) {
    if(beg > end)
        return -1;
    
    int mid = (beg + end) / 2;
    if(BFS(vertexes, vertex, srt, fin , mid)) {
        int a = binarysearch(vertexes, vertex, srt, fin, mid + 1, end);
        if(a == -1)
            return mid;
        else
            return a;
    } else {
        return binarysearch(vertexes, vertex, srt, fin, beg, mid - 1);
    }
}

int main(int argc, const char * argv[]) {
    int vertex, a, b, length_edge, max_edge = 0, srt, fin, edge, x;
    cin>>vertex;
    vector<pair<int, int>>vertexes[100];
    cin>>edge;
    for(int i = 0; i < edge; i++) {
        cin>>a;
        cin>>b;
        cin>>length_edge;
        max_edge = max(max_edge, length_edge);
        vertexes[a].push_back(make_pair(b, length_edge));
        vertexes[b].push_back(make_pair(a, length_edge));
    }
    
    cout<<"Start: ";
    cin>>srt;
    cout<<"Fin: ";
    cin>>fin;
    
    x = binarysearch(vertexes, vertex, srt, fin, 0, max_edge);
    cout<<x;
    
    return 0;
}
