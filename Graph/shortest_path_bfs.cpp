#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void shortest_path(vector<int>vertexes[], int count, int vertex, int srt, int dest) {
    queue<int>q;
    int visited[count];
    for(int i = 0; i < count; i++) {
        visited[i] = 0;
    }
    q.push(srt);
    visited[srt] = 1;
    int trace[count];
    int x = srt, flag = 0;
    while(q.size() > 0) {
        x = q.front();
        q.pop();
        for(int i = 0; i < vertexes[x].size(); i++) {
            if(visited[vertexes[x][i]] == 0) {
                trace[vertexes[x][i]] = x;
                q.push(vertexes[x][i]);
                visited[vertexes[x][i]] = 1;
                if(vertexes[x][i] == dest) {
                    flag = 1;
                    break;
                }
                
            }
        }
        if(flag == 1)
            break;
    }
    
    vector<int>temp;
    if(flag == 1) {
        x = dest;
        temp.push_back(x);
        while(x != srt) {
            temp.push_back(trace[x]);
            x = trace[x];
        }
        for(int i = temp.size() - 1; i >= 0; i--) {
            if(temp[i] < vertex) {
                cout<<temp[i]<<" ";
            }
        }
        cout<<"\n";
    } else {
        cout<<"No path\n";
    }
    return;
}

int main(int argc, const char * argv[]) {
    int vertex, prev_v;
    cin>>vertex;
    vector<int>vertexes[100];
    int edge;
    cin>>edge;
    int a, b, length_edge;
    int count = vertex;
    for(int i = 0; i < edge; i++) {
        cin>>a;
        cin>>b;
        cin>>length_edge;
       
        prev_v = a;
        for(int j = 0; j < length_edge - 1; j++) {
            vertexes[prev_v].push_back(count);
            vertexes[count].push_back(prev_v);
            prev_v = count;
            j++;
            count ++;
        }
        vertexes[prev_v].push_back(b);
        vertexes[b].push_back(prev_v);
    }
    int srt, dest;
    cout<<"Start: ";
    cin>>srt;
    cout<<"Dest: ";
    cin>>dest;
    shortest_path(vertexes, count, vertex, srt, dest);
    return 0;
}
