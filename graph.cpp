#include "graph.h"

/*
/ Searches the airport csv file for the starting airport specified by the user.
/ Returns the airport ID if the airport is found.
/ If the airport is not found, prints error message and exits code.
*/
int locateStart(std::string airports_file; std::string start) {
    fstrem fs(airports_file);

    string currLine;
    while(getLine(fs, currLine)) {
        if (currLine.find(start, 0) != std::string::npos) {
            int airportID = currLine.substr(0, currLine.find(','));
            return airportID;
        }
    }

    std::cout << "This staring airport cannot be found.  Please check you input and try again." << std::endl;
    exit(1);
}

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