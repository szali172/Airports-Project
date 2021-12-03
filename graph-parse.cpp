#include "graph.h"

Graph::Graph(std::string airports_file, std::string routes_file) {
    // push back so that 0th index is already filled
    adjacency_list.push_back(new Edge{std::pair<double, double>(0, 0), nullptr});

    std::ifstream data(airports_file);
    std::string line;

    double longitude;
    double latitude;

    const size_t LONGITUDE_INDEX = 6;
    const size_t LATITUDE_INDEX = 7;
    int fileIndex = 0;

    // gives us an index to insert into, starts at 1 because we don't want to insert into 0th
    int index = 1;

    while (std::getline(data, line)) {
        std::stringstream lineStream(line);
        std::string aCell;
        fileIndex = 0;

        while (std::getline(lineStream, aCell, ',')) {
            if (fileIndex == LONGITUDE_INDEX) {
                longitude = std::stod(aCell);
            } else if (fileIndex == LATITUDE_INDEX) {
                latitude = std::stod(aCell);
            }
            ++fileIndex;
        }
        
        // inserting new node with no edges so far into current spot in adjacency list
        adjacency_list[index] = new Edge{std::pair<double, double>(longitude, latitude), nullptr};
    }
} 