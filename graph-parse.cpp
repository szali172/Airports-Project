#include "graph.h"

Graph::Graph(std::string airports_file, std::string routes_file) {
    airportParse(airports_file);
    routeParse(routes_file);
}

void Graph::airportParse(std::string airports_file) {
    // push back so that 0th index is already filled
    adjacency_list.push_back(new Edge{std::pair<double, double>(0, 0), nullptr});

    std::ifstream data(airports_file);
    std::string line;

    double latitude;
    double longitude;
    
    const size_t LATITUDE_INDEX = 7;
    const size_t LONGITUDE_INDEX = 6;

    // gives us an index to insert into, starts at 1 because we don't want to insert into 0th
    int index = 1;

    while (std::getline(data, line)) {
        std::stringstream lineStream(line);
        std::string aCell;
        int csvCol = 0;

        while (std::getline(lineStream, aCell, ',')) {
            if (csvCol == 0) {
                while(index != std::stoi(aCell)) {
                    adjacency_list[index] = NULL;
                    ++index;
                }
            }
            if (csvCol == LATITUDE_INDEX) {
                latitude = std::stoi(aCell);
            } else if (csvCol == LONGITUDE_INDEX) {
                longitude = std::stoi(aCell);
            }
            ++csvCol;
        }
        
        // inserting new node with no edges so far into current spot in adjacency list
        adjacency_list[index] = new Edge{std::pair<double, double>(latitude, longitude), nullptr};
        index++;
    }
}

void Graph::routeParse(std::string routes_file) {
    std::ifstream data(routes_file);
    std::string line;

    double source_id;
    double destination_id;

    const size_t SOURCE_INDEX = 3;
    const size_t DESTINATION_INDEX = 5;

    // gives us an index to insert into, starts at 1 because we don't want to insert into 0th
    int index = 1;

    while (std::getline(data, line)) {
        std::stringstream lineStream(line);
        std::string aCell;
        int csvCol = 0;

        while (std::getline(lineStream, aCell, ',')) {
            if (csvCol == SOURCE_INDEX) {
                source_id = std::stoi(aCell);
            } else if (csvCol == DESTINATION_INDEX) {
                destination_id = std::stoi(aCell);
            }
            ++csvCol;
        }
        
        // insert destination airport to the last edge in the adjacency list in the source airport
        Edge* current_edge = adjacency_list[source_id];
        while (adjacency_list[source_id]->next != NULL) {
            current_edge = current_edge->next;
        }
        current_edge->next = adjacency_list[destination_id];

        index++;
    }
}