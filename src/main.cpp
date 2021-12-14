#include "../parse-dijkstra/include/graph.h"
#include "../visual-dfs/include/visual.h"

#include <iostream>
#include <string>


int main(int argc, char** argv) {
    // if (argc != 6) {
    //     std::cout << "You do not have the right number of arguments (5)" << std::endl;
    //     return 1;
    // }

    // std::string airport_data_loc = argv[1];
    // std::string route_data_loc = argv[2];
    // std::string source_airport = argv[3];
    // std::string dest_airport = argv[4];
    // std::string map_file = argv[5];

    // // create graph/adjacency list with all airports and all connections
    // Graph* graph = new Graph(airport_data_loc, route_data_loc);
    // // run dijkstra's on it, include source airport
    // int source = graph->locateStart(airport_data_loc, source_airport);
    // graph->dijkstra(*graph, source);
    // // print output (new adjacency list representing SSSP) to map PNG
    // PNG get_image_file;
    // get_image_file.readFromFile(map_file);
    // PNG result = Visual::visual(*graph, get_image_file);
    // result.writeToFile(map_file);

    return 0;
}