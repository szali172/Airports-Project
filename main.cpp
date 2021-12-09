#include "graph.h"

#include <iostream>

int main() {
   // create graph/adjacency list with all airports and all connections
    Graph* graph = new Graph("airports.csv", "routes.dat");
    // run dijkstra's on it, include source airport
    int source = locateStart("airports.csv", "ORD");
    graph->dijkstra(graph, source);
    // print output (new adjacency list representing SSSP) to map PNG

    return 0;
}