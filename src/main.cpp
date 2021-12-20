#include "../parse-dijkstra/include/graph.h"
#include "../visual-dfs/include/visual.h"

#include <iostream>
#include <string>


int main() {

    std::string airport;
    std::cout << "Enter Airport Name or IATA Code (i.e. \"Chicago O'Hare International Airport\" or \"ORD\") : ";
    std::cin >> airport;

    Graph airports("./data/airports.csv", "./data/routes.csv");
    int start = airports.locateStart("./data/airports.csv", airport);
    Graph dijkstra = airports.dijkstra(airports.adjacency_list, start);
    std::cout << "Compiling..." << std::endl;
    
    PNG input;
    input.readFromFile("./data/base_map.png");
    PNG original = Visual::visual(airports, input);
    PNG dijkstra_picture = Visual::visual(dijkstra, input);

    original.writeToFile("original.png");
    dijkstra_picture.writeToFile("dijkstra_picture.png");
    std::cout << "Complete!" << std::endl;

    return 0;
}