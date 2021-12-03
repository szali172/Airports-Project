#include "graph.h"

/* 
/ Dijkstra's algorithm to find the shortest path for a graph using adjacency list
*/
Graph* dijkstra(Graph *graph, int start) {
    for (Vertex v : graph) {
        dist[v] = +inf;
        prev[v] = NULL;
    }
    dist[start] = 0;
    PriorityQueue Q;
    Q.makeHeap(graph.vertices());
    Graph T;

    for (int i = 0; i < n; i++) {
        Vertex u = Q.removeMin();
        T.add(u);
        for (Vertex v : )
    }

    while(!Q.empty()) {
        Vertex u = Q.removeMin();
        T.add(u);
        for (list<node>::iterator iter = graph.adjList[u].begin(); iter != graph.adjList[u].end(); iter++) {
            if ((dist[u] + iter->cost) < dist[iter->dest]) {
                dist[iter->dest] = dist[u] + iter->cost;
                prev[iter->dest] = u;
            }
        }
    }

    return T;
}