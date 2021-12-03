#include "graph.h"

Graph::Graph(std::string airports_file, std::string routes_file) {
    std::ifstream data(airports_file);
    std::string line;

    double longtitude;
    double latitude;

    const size_t LONGITUDE_INDEX = 6;
    const size_t LATITUDE_INDEX = 7;
    int fileIndex = 0;

    while (std::getline(data, line)) {
        std::stringstream lineStream(line);
        std::string aCell;
        fileIndex = 0;

        while (std::getline(lineStream, aCell, ',')) {
            if (fileIndex == LONGITUDE_INDEX) {
                longtitude = std::stod(aCell);
            } else if (fileIndex == LATITUDE_INDEX) {
                latitude = std::stod(aCell);
            }
            ++fileIndex;
        }

        adjacency_list->push_back(new Edge{std::pair<double, double>(longtitude, latitude), nullptr});
    }
}