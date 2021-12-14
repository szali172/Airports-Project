// #include "include/adder.h"
#include <iostream>

#include "graph.h"
#include <vector>

int main() {
    std::vector<Graph::Edge*> adjacency_list;

    Graph::Edge* edge1 = new Graph::Edge(std::make_pair(1.0, 80.0), "one");
    Graph::Edge* edge2 = new Graph::Edge(std::make_pair(2.0, 54.0), "two");
    Graph::Edge* edge3 = new Graph::Edge(std::make_pair(3.0, 25.0), "three");
    Graph::Edge* edge4 = new Graph::Edge(std::make_pair(4.0, 69.0), "four");

    Graph::Edge* neighbor12 = new Graph::Edge(std::make_pair(2.0, 4.0), "one");
    Graph::Edge* neighbor13 = new Graph::Edge(std::make_pair(3.0, 5.0), "one");

    Graph::Edge* neighbor23 = new Graph::Edge(std::make_pair(3.0, 8.0), "one");

    Graph::Edge* neighbor34 = new Graph::Edge(std::make_pair(4.0, 6.0), "one");

    edge1->next = neighbor12;
    neighbor12->next = neighbor13;

    edge2->next = neighbor23;

    edge3->next = neighbor34;

    adjacency_list.push_back(NULL);
    adjacency_list.push_back(edge1);
    adjacency_list.push_back(edge2);
    adjacency_list.push_back(edge3);
    adjacency_list.push_back(edge4);

    Graph graph(adjacency_list);

    std::vector<Graph::Edge*> output = graph.dijkstra(graph.adjacency_list, 1.0);

    for (unsigned i = 1; i < output.size(); i++) {
        std::cout << i << std::endl;
        Graph::Edge* neighbor = output[i]->next;
        while (neighbor != NULL) {
            std::cout << " -> (" << neighbor->data.first << ", " << neighbor->data.second << ") " << std::endl;
            neighbor = neighbor->next;
        }
    }
    
    return 0;
}