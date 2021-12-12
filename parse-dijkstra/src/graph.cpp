#include "graph.h"
#include <list>
#include <cmath>
#include <math.h>

/**
* Constructs an empty graph
* Both Vertex and Edge list will be empty
*/
Graph::Graph() {}


/**
 * @brief when user passes in starting airport
 * Parses through airports csv file until it finds a matching airport
 * Passed string could be an Airport name or IATA code
 * If no matching string is found, produce an error message
 * @param airports_file csv to parse
 * @param start starting airport to search for
 * @return index of starting airport (Airport ID)
 */
int locateStart(std::string airports_file, std::string start) {
    std::ifstream fs(airports_file);    //get airport csv file into the ifstream to be parsed

    std::string currLine;
    while(std::getline(fs, currLine)) { //goes through every line in the csv file to find the starting airport (start param)
        if (currLine.find(start, 0) != std::string::npos) {
            int airportID = std::stoi(currLine.substr(0, currLine.find(',')));
            return airportID;
        }
    }

    std::cout << "This staring airport cannot be found. Please check your input and try again." << std::endl;
    exit(1);
}


/**
* @brief Dijkstra's algorithm on our directed and weighted graph to find the shortest path for a graph using adjacency list
* @param graph perform algorithm on this passed graph
* @param starting node
* @return SSSP graph
*/
Graph* Graph::dijkstra(Graph* graph, int start) {   //TODO finish up this function and add useful comments
    /*
    for (Vertex v : graph) {
        dist[v] = +inf;
        prev[v] = NULL;
    }
    dist[start] = 0;
    PriorityQueue Q;
    Q.makeHeap(graph.vertices());
    Graph T;
    for (int i = 0; i < n; i++) {
        Vertex u = Q.removeMin();
        T.add(u);
        for (Vertex v : )
    }
    while(!Q.empty()) {
        Vertex u = Q.removeMin();
        T.add(u);
        for (list<node>::iterator iter = graph.adjList[u].begin(); iter != graph.adjList[u].end(); iter++) {
            if ((dist[u] + iter->cost) < dist[iter->dest]) {
                dist[iter->dest] = dist[u] + iter->cost;
                prev[iter->dest] = u;
            }
        }
    }
    */
   return nullptr;
}


/**
* @brief Calculates the distance between two coordinates in the world map (2 dimensions, longitude and latitude)
* 
* @param longitude1 Longitude of first point
* @param latitude1 Latitude of first point
* @param longitude2 Longitude of second point
* @param latitude2 Latitude of second point
* @return The distance between two points in kilometers
*/
double Graph::calculateDistance(double longitude1, double latitude1, double longitude2, double latitude2) {
    // getting distance in KILOMETERS
    double dist = -1.0;
    double earth_radius = 6371;

    double lat1_radians = latitude1 * (M_PI / 180);
    double lat2_radians = latitude1 * (M_PI / 180);

    double lon1_radians = longitude1 * (M_PI / 180);    //TODO fix this??? (it was commented out originally)
    double lon2_radians = longitude2 * (M_PI / 180);    //TODO fix this??? (it was commented out originally)

    double lat_difference_radians = (latitude2 - latitude1) * (M_PI / 180);
    double long_difference_radians = (longitude2 - longitude1) * (M_PI / 180);

    // setting up a variables a and c for haversine formula
    double a = ((sin(lat_difference_radians / 2) * sin(lat_difference_radians / 2)) + (cos(lat1_radians) * cos(lat2_radians) * sin(long_difference_radians / 2) * sin(long_difference_radians / 2)));
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    dist = earth_radius * c;    //calculates haversine formula to calculate distance between 2 points on earth

    return dist;
}


/**
* @brief Adds an edge to a Graph
* @param index index of the vertex the edge will be linked to
* @param edge edge to be added at that index
*/
void Graph::addEdge(int index, Edge* edge) {
    if (index <= 0) {
        std::cout << "This is not a valid index to add an edge in (index > 0)." << std::endl;
        exit(1);
    }

    // insert edge to front of airport's list:
    Edge* temp = adjacency_list[index]->next;
    adjacency_list[index]->next = edge;
    edge->next = temp;
}

/**
* @brief Adds a vertex to the adjacency list
* Pushes vertex to end of the list
* 
* @param vertex the vertex to be pushed to the end of the adjacency list
*/
void Graph::addVertex(Edge* vertex) {
    adjacency_list.push_back(vertex);
}

void Graph::setStart(int index) {
    start_ = index;
}