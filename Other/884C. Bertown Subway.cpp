#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Node {
    int vertexNumber;
    struct Node *next;
};

struct Graph {
    int V;
    struct Node *Adj;
};

struct Graph *createGraph(int n, int a[]) {
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    G->V = n;
    for(int i = 0; i < n; i++) {
        G->Adj[i].vertexNumber = a[i] - 1;
        G->Adj[i].next = NULL;
    }
    return G;
}

struct Graph *addEdge(struct Graph *G, int a[]) {
    for(int i = 0; i < G->V; i++) {
        G->Adj[i].next = (struct Node *)malloc(sizeof(struct Node));
        G->Adj[i].next->vertexNumber = a[i];
    }
    return G;
}
void swap(int *a, int *b) {
    int *stuff;
    stuff = a;
    b = a;
    a = stuff;
    return;
}

int subway(int n, int a[]) {
    int tmp[n];
    int output;
    int stuff;
    struct Graph *G = createGraph(n, a);
    G = addEdge(G, a);
    for(int i = 0; i < n; i++)
        tmp[i] = a[i];
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            stuff = tmp[i];
            tmp[i] = tmp[j];
            tmp[j] = stuff;
        }
    }
    return output;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int output = subway(n, a);
    cout<<output;
    return 0;
}
