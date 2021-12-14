
#include "../parse-dijkstra/include/graph.h"

#include <iostream>
#include "../parse-dijkstra/include/graph.h"
//#include "../include/graph.h"


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

    Graph airports("../data/airports.csv", "../data/routes.csv");

    std::cout << "hello" << airports.adjacency_list.size() << std::endl;

    Graph output = graph.dijkstra(graph.adjacency_list, 1.0);

    for (unsigned i = 1; i < output.adjacency_list.size(); i++) {
        std::cout << i << std::endl;
        Graph::Edge* neighbor = output.adjacency_list[i]->next;
        while (neighbor != NULL) {
            std::cout << " -> (" << neighbor->data.first << ", " << neighbor->data.second << ") " << std::endl;
            neighbor = neighbor->next;
        }
    }
    // Node n("5");
    // Node n2("6");

    // Adder::Adder a(n, n2);

    // std::cout << a.getResult() << std::endl;
    // std::cout << Node::num_nodes_ << std::endl;
    /*
    std::vector<Graph::Edge*> adjacency_list;

    Graph::Edge* firstedge = new Graph::Edge(std::make_pair(1, 0), "one");
    Graph::Edge* secondedge = new Graph::Edge(std::make_pair(2, 0), "two");
    firstedge->next = secondedge;
    Graph::Edge* thirdedge = new Graph::Edge(std::make_pair(3, 0), "three");
    Graph::Edge* fourthedge = new Graph::Edge(std::make_pair(4, 0), "four");

    adjacency_list.push_back(firstedge);
    adjacency_list.push_back(secondedge);
    adjacency_list.push_back(thirdedge);
    */
   /*

           struct Edge {
            std::string label;
            Edge* next = nullptr;
            double prev_index;
            
            std::pair<double, double> data = std::make_pair(0.0, 0.0);
            std::string label = "UNEXPLORED";

            Edge(std::pair<double, double> data_, std::string label_) {
                data = data_;
                label = label_;
            }
            Edge(std::pair<double, double> data_, double prev_index_) {
                data = data_;
                prev_index = prev_index_;
            }
        };

        class EdgeComparator {
            public:
                double operator()(Edge* edge1, Edge* edge2) {
                    return edge1->data.second > edge2->data.second;
                }
        };
    */

    return 0;
}