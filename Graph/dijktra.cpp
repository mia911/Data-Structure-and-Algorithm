#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

int minDistIdx(vector<pair<int, int>>vertexes[], int vertex, int srt, int dist[], int visited[]) {
    int mindistance = INT_MAX;
    int mindistanceidx = -1;
    for(int i = 0; i < vertex; i++) {
        if(dist[i] <= mindistance && visited[i] == 0) {
            mindistance = dist[i];
            mindistanceidx = i;
        }
    }
    return mindistanceidx;
}

void dijkstra(vector<pair<int, int>>vertexes[], int vertex, int srt) {
    int visited[vertex];
    int dist[vertex], x;
    int path[vertex];
    pair<int, int> v;
    for(int i = 0; i < vertex; i++) {
        visited[i] = 0;
        dist[i] = INT_MAX;
    }
    
    dist[srt] = 0;
    path[srt] = -1;
    
    for(int i = 0; i < vertex; i++) {
        //min index to consider next
        x = minDistIdx(vertexes, vertex, srt, dist, visited);
        if(x == -1)
            break;
        
        visited[x] = 1;
        
        //update next index distance
        for(int j = 0; j < vertexes[x].size(); j++) {
            //check if the distance is min
            v = vertexes[x][j];
            if(dist[v.first] > dist[x] + v.second) {
                dist[v.first] = dist[x] + v.second;
                path[v.first] = x;
            }
        }
    }
    
    for(int i = 0; i < vertex; i++) {
        if(i != srt) {
            int tmp = i;
            while(1) {
                cout<<tmp<<" ";
                tmp = path[tmp];
                if(tmp == -1)
                    break;
            }
            cout<<"\n";
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    int vertex;
    cin>>vertex;
    vector<pair<int, int>>vertexes[100];
    int edge;
    cin>>edge;
    int a, b, length_edge;
    for(int i = 0; i < edge; i++) {
        cin>>a;
        cin>>b;
        cin>>length_edge;
        
        vertexes[a].push_back(make_pair(b, length_edge));
        vertexes[b].push_back(make_pair(a, length_edge));
    }
    
    int srt;
    cout<<"Start: ";
    cin>>srt;
    dijkstra(vertexes, vertex, srt);
    return 0;
}
