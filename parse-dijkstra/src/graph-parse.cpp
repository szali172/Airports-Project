#include "../include/graph.h"

/**
* @brief Constructs the Vertex list, but not the Edges
* Used for Dijkstra's
* Constructs the adjacency list by filling in all the information from the CSV file
* 
* @param airports_file CSV file containing all the airports and their specific location in the world (latitude and longitude in 2d space)
*/
Graph::Graph(std::string airports_file) {
    airportParse(airports_file);
}


/**
* @brief Constructs both Vertex and Edge list
* Used for Dijkstra's
* Constructs the vertexes adjacency list by filling in all the information from the CSV file
* Constructs the edges for the adjacency by examining all the possible routes between two airports from the CSV file
*
* @param airports_file CSV file containing all the airports and their specific location in the world (latitude and longitude in 2d space)
* @param routes_file CSV file containing all the possible routes between 2 different airports
*/
Graph::Graph(std::string airports_file, std::string routes_file) {
    airportParse(airports_file);
    routeParse(routes_file);
}


/**
* @brief Private helper function for the Graph constructor (both the one parameter and two parameter constructors)
* Constructs the Vertex list, but not the Edges
* Used for Dijkstra's
* Constructs the vertexes adjacency list by filling in all the information from the CSV file
* @param airports_file CSV file containing all the airports and their specific location in the world (latitude and longitude in 2d space)
*/
void Graph::airportParse(std::string airports_file) {
    // push back so that 0th index is already filled
    adjacency_list.push_back(new Edge{std::pair<double, double>(0, 0), nullptr});

    std::ifstream data(airports_file);  //get airport csv file into the ifstream to be parsed
    std::string line;

    double latitude;
    double longitude;
    
    const size_t LATITUDE_INDEX = 7;    //location within the airports_file that has the latitude value of the airport
    const size_t LONGITUDE_INDEX = 6;   //location within the airports_file that has the longitude value of the airport

    // gives us an index to insert into, starts at 1 because we don't want to insert into 0th
    int index = 1;

    while (std::getline(data, line)) {
        std::stringstream lineStream(line);
        std::string aCell;
        int csvCol = 0;

        while (std::getline(lineStream, aCell, ',')) {  //goes through every comma within every line in the csv file
            if (csvCol == 0) {
                while(index != std::stoi(aCell)) {      //if the airport_id (first col of every line) is not sequential, push back 
                                                        //null verticies to keep the airport and routes CSV files consistent with the adjacency list
                    adjacency_list[index] = NULL;
                    ++index;
                }
            }
            if (csvCol == LATITUDE_INDEX) {
                latitude = std::stoi(aCell);            //store latitude value if the current cell is at the right index
            } else if (csvCol == LONGITUDE_INDEX) {
                longitude = std::stoi(aCell);           //store longitude value if the current cell is at the right index
            }
            ++csvCol;
        }
        
        // inserting new node with no edges so far into current spot in adjacency list
        adjacency_list[index] = new Edge{std::pair<double, double>(latitude, longitude), nullptr};
        index++;
    }
}


/**
* @brief Private helper function for the Graph constructor (only for the two parameter constructors)
* Constructs the Edges list, but not the Vertex list (is required to be constructed before calling the routes [this] function)
* Used for Dijkstra's
* Constructs the vertexes adjacency list by filling in all the information from the CSV file
* @param routes_file CSV file containing all the possible routes between 2 different airports
*/
void Graph::routeParse(std::string routes_file) {
    std::ifstream data(routes_file);    //get routes csv file into the ifstream to be parsed
    std::string line;

    double source_id;
    double destination_id;

    const size_t SOURCE_INDEX = 3;      //location within the routes_file that has the source airport value
    const size_t DESTINATION_INDEX = 5; //location within the routes_file that has the destination airport value

    // gives us an index to insert into, starts at 1 because we don't want to insert into 0th
    int index = 1;

    while (std::getline(data, line)) {  //goes through every comma within every line in the csv file
        std::stringstream lineStream(line);
        std::string aCell;
        int csvCol = 0;

        while (std::getline(lineStream, aCell, ',')) {
            if (csvCol == SOURCE_INDEX) {
                source_id = std::stoi(aCell);       //store source airport value if the current cell is at the right index
            } else if (csvCol == DESTINATION_INDEX) {
                destination_id = std::stoi(aCell);  //store destination airport value if the current cell is at the right index
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