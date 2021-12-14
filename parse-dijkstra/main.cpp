
#include "../parse-dijkstra/include/graph.h"

#include <iostream>
#include "../parse-dijkstra/include/graph.h"
//#include "../include/graph.h"


int main() {
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