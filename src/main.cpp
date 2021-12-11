// #include "graph.h"
#include "parser_header.h"

#include <iostream>
#include <string>

using Parser::Node;

int main() {
    // // create graph/adjacency list with all airports and all connections
    // Graph* graph = new Graph("airports.csv", "routes.dat");
    // // run dijkstra's on it, include source airport
    // int source = graph->locateStart("airports.csv", "ORD");
    // graph->dijkstra(graph, source);
    // // print output (new adjacency list representing SSSP) to map PNG

    std::cout << "Hello World!" << std::endl;
    Node n("3");
    std::cout << n.getData() << std::endl;
    std::cout << n.num_nodes_ << std::endl;
    Node n2("ben");
    std::cout << n.num_nodes_ << std::endl;

    return 0;
}