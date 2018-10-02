//
//  main.c
//  WeightedShortestPath
//
//  Created by Trang Nguyen on 8/13/17.
//  Copyright © 2017 Trang Nguyen. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#define V 9 

int minDistance(int vst[], int dist[]) {
	int min_vertex = -1;
	int min = INT_MAX;
	int i;
	for(i = 0; i < V; i++) {
		if(vst[i] == 0) {
			if(dist[i] < min) {
				min = dist[i];
				min_vertex = i;
			}
		}
	}
	return min_vertex;
}

void printSolution(int distance[], int path[], int v, int src) { //src la dinh dau tien duyet
    printf("Vertex\t Distance\t\tPath\n");
    int i;
    for (i = 0; i < v; i++) {
        printf("\n%d -> %d\t\t%d\t\t%d ",src, i, distance[i], src);
        printPath(path, i);
    }
    printf("\n");
}

void Dijkstra(int a[V][V], int s) { //ham ma tran(2 bien_ bat buoc phai co so luong phan tu trong ma tran. s: dinh bat dau
    int visited[V], distance[V], path[V];
    int i, j;
    for(i = 0; i < V; i++) {
        visited[i] = 0;
        distance[i] = INT_MAX;
        path[i] = -1;
    }
    distance[s] = 0;
    for(i = 0; i < V; i++) {
    	int min_vertex = minDistance(visited, distance);
    	visited[min_vertex] = 1;
        for(j = 0; j < V; j++) {
        	if(visited[j] == 0 && a[min_vertex][j] != 0) {
        		if(distance[min_vertex] + a[min_vertex][j] < distance[j]) {
        			path[j] = min_vertex;
        			distance[j] = distance[min_vertex] + a[min_vertex][j];
				}
			}
		}
    }
 	printSolution(distance, path, V, s);   
}


int main(int argc, const char * argv[]) {
    int graph[9][9] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
                        {4, 0, 8, 0, 0, 0, 0, 11, 0},
                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 1, 6},
                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
                        {0, 0, 2, 0, 0, 0, 6, 7, 0}
                      };
                      
    Dijsktra(graph, 0);
    return 0;
}
