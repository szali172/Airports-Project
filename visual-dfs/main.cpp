// #include "include/adder.h"
#include <iostream>

#include "graph.h"
#include <vector>

int main() {
    
   
    std::vector<Graph::Edge*> adjacency_list;

    Graph::Edge* firstedge = new Graph::Edge(std::make_pair(1.0, 0.0), "one");
    Graph::Edge* secondedge = new Graph::Edge(std::make_pair(2.0, 5.0), "two");
    Graph::Edge* thirdedge = new Graph::Edge(std::make_pair(3.0, 3.0), "three");
    Graph::Edge* fourthedge = new Graph::Edge(std::make_pair(4.0, 2.0), "four");

    //std::cout << "secondedge data.second: " << secondedge->data.second << std::endl;

    // representing distance from firstedge
    Graph::Edge* neighbor12 = new Graph::Edge(std::make_pair(2.0, 4.0), "two");
    Graph::Edge* neighbor13 = new Graph::Edge(std::make_pair(3.0, 2.0), "three");

    firstedge->next = neighbor12;
    firstedge->next->next = neighbor13;

    Graph::Edge* neighbor24 = new Graph::Edge(std::make_pair(4.0, 6.0), "four");
    secondedge->next = neighbor24;

    Graph::Edge* neighbor32 = new Graph::Edge(std::make_pair(2.0, 7.0), "two");
    Graph::Edge* neighbor34 = new Graph::Edge(std::make_pair(4.0, 8.0), "four");

    thirdedge->next = neighbor32;
    thirdedge->next->next = neighbor34;

    adjacency_list.push_back(NULL);
    adjacency_list.push_back(firstedge);
    adjacency_list.push_back(secondedge);
    adjacency_list.push_back(thirdedge);
    adjacency_list.push_back(fourthedge);

    
    for (unsigned i = 1; i < adjacency_list.size(); i++) {
        //std::cout << "Current vertext in list: " << adjacency_list[i]->data.first << std::endl;
        std::cout << adjacency_list[i]->data.first << std::endl;

        Graph::Edge* neighbor = adjacency_list[i]->next;
        while (neighbor != NULL) {
            //std::cout << "Current neighbor of current vertex: " << neighbor->data.first << std::endl;
            std::cout << " -> (" << neighbor->data.first << ", " << neighbor->data.second << ")" << std::endl;
            //std::cout << "Current neighbor's distance to current vertex: " << neighbor->data.second << std::endl;
            neighbor = neighbor->next;
        }
    }
    

    Graph graph(adjacency_list);
    
    Graph output = graph.dijkstra(adjacency_list, 1.0);

    for (unsigned i = 1; i < output.adjacency_list.size(); i++) {
        //std::cout << "Current vertext in list: " << output[i]->data.first << std::endl;
        std::cout << output.adjacency_list[i]->data.first << std::endl;
        Graph::Edge* neighbor = output.adjacency_list[i]->next;
        while (neighbor != NULL) {
            //std::cout << "Current neighbor of current vertex: " << neighbor->data.first << std::endl;
            //std::cout << "Current neighbor's distance to current vertex: " << neighbor->data.second << std::endl;
            std::cout << " -> (" << neighbor->data.first << ", " << neighbor->data.second << ")" << std::endl;
            neighbor = neighbor->next;
        }
    }
    
    return 0;
}