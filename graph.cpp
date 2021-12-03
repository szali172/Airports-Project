#include "graph.h"
#include <list>


/* 
/ Dijkstra's algorithm to find the shortest path for a graph using adjacency list
*/
// graph = adjacency_list after all airports and all neighbors have been added
Graph* Graph::dijkstra(Graph graph, int start) {
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
        
    }
}

void Graph::addEdge(int index, Edge* edge) {
    // DO NOT ADD ANYTHING TO INDEX 0
    adjacency_list[index].push_back(edge);
}