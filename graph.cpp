<<<<<<< HEAD
#include "graph.h"
#include <list>
#include <cmath>
#include <math.h>
#include <limits>
#include <queue>

/*
/ Searches the airport csv file for the starting airport specified by the user.
/ Returns the airport ID if the airport is found.
/ If the airport is not found, prints error message and exits code.
*/
int locateStart(std::string airports_file, std::string start) {
    std::ifstream fs(airports_file);

    string currLine;
    while(std::getline(fs, currLine)) {
        if (currLine.find(start, 0) != std::string::npos) {
            int airportID = std::stoi(currLine.substr(0, currLine.find(',')));
            return airportID;
        }
    }

    std::cout << "This staring airport cannot be found. Please check your input and try again." << std::endl;
    exit(1);
}

/* 
/ Dijkstra's algorithm to find the shortest path for a graph using adjacency list
*/
// graph = adjacency_list after all airports and all neighbors have been added
Graph* Graph::dijkstra(Graph* graph, int start) {
    int inf = std::numeric_limits<int>::max();
    Edge* prev;

    for (Edge* v : adjacency_list) {
        v->data.second = inf;
        v->prev = NULL;
    }
    adjacency_list[start]->data.second = 0;
    std::priority_queue<int> pq;
    
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
   return nullptr;
}

void Graph::addEdge(int index, Edge* edge) {
    // DO NOT ADD ANYTHING TO INDEX 0
    // adjacency list visual:
    // [airport 1]->[edge 1 (airport ID, distance to airport 1)]->[edge 2 (airport ID, distance to airport 1)]
    // [airport 2]->[edge 1 (airport ID, distance to airport 2)]->[edge 2 (airport ID, distance to airport 2)]
    // [airport 3]->[edge 1 (airport ID, distance to airport 3)]

    // insert edge to front of airport's list:
    Edge* temp = adjacency_list[index]->next;
    adjacency_list[index]->next = edge;
    edge->next = temp;
}

void addVertex(Edge* vertex) {
    adjacency_list.push_back(vertex);
}

double Graph::calculateDistance(double longitude1, double latitude1, double longitude2, double latitude2) {
    // getting distance in KILOMETERS
    double dist = -1.0;
    double earth_radius = 6371;

    double lat1_radians = latitude1 * (M_PI / 180);
    double lat2_radians = latitude1 * (M_PI / 180);

    //double lon1_radians = longitude1 * (M_PI / 180);
    //double lon2_radians = longitude2 * (M_PI / 180);

    double lat_difference_radians = (latitude2 - latitude1) * (M_PI / 180);
    double long_difference_radians = (longitude2 - longitude1) * (M_PI / 180);

    // setting up a variables a and c for haversine formula
    double a = ((sin(lat_difference_radians / 2) * sin(lat_difference_radians / 2)) + (cos(lat1_radians) * cos(lat2_radians) * sin(long_difference_radians / 2) * sin(long_difference_radians / 2)));
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    dist = earth_radius * c;

    return dist;
}

void replace(Edge* toReplace, Edge* toInsert) {
    pq.remove(toReplace);
    pq.push(toInsert);
}

void remove(double element) {
    std::priority_queue <Edge*, std::vector<Edge*>, Graph::EdgeComparator> pq_helper;

    while (!(pq.empty())) {
        if (pq.top()->data.second != element) {
            pq_helper.push(pq.top());
            pq.pop();
        } else {
            pq.pop();
        }
    } 
=======
#include "graph.h"
#include <list>
#include <cmath>
#include <math.h>

/**
* Constructs an empty graph
* Both Vertex and Edge list will be empty
*/
Graph::Graph() {
    map.readFromFile("base_map.png");
}


/*
/ Searches the airport csv file for the starting airport specified by the user.
/ Returns the airport ID if the airport is found.
/ If the airport is not found, prints error message and exits code.
*/
int locateStart(std::string airports_file, std::string start) {
    std::ifstream fs(airports_file);

    string currLine;
    while(std::getline(fs, currLine)) {
        if (currLine.find(start, 0) != std::string::npos) {
            int airportID = std::stoi(currLine.substr(0, currLine.find(',')));
            return airportID;
        }
    }

    std::cout << "This staring airport cannot be found. Please check your input and try again." << std::endl;
    exit(1);
}

/* 
/ Dijkstra's algorithm to find the shortest path for a graph using adjacency list
*/
// graph = adjacency_list after all airports and all neighbors have been added
Graph* Graph::dijkstra(Graph* graph, int start) {
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

void Graph::addEdge(int index, Edge* edge) {
    // DO NOT ADD ANYTHING TO INDEX 0
    // adjacency list visual:
    // [airport 1]->[edge 1 (airport ID, distance to airport 1)]->[edge 2 (airport ID, distance to airport 1)]
    // [airport 2]->[edge 1 (airport ID, distance to airport 2)]->[edge 2 (airport ID, distance to airport 2)]
    // [airport 3]->[edge 1 (airport ID, distance to airport 3)]

    // insert edge to front of airport's list:
    Edge* temp = adjacency_list[index]->next;
    adjacency_list[index]->next = edge;
    edge->next = temp;
}

double Graph::calculateDistance(double longitude1, double latitude1, double longitude2, double latitude2) {
    // getting distance in KILOMETERS
    double dist = -1.0;
    double earth_radius = 6371;

    double lat1_radians = latitude1 * (M_PI / 180);
    double lat2_radians = latitude1 * (M_PI / 180);

    //double lon1_radians = longitude1 * (M_PI / 180);
    //double lon2_radians = longitude2 * (M_PI / 180);

    double lat_difference_radians = (latitude2 - latitude1) * (M_PI / 180);
    double long_difference_radians = (longitude2 - longitude1) * (M_PI / 180);

    // setting up a variables a and c for haversine formula
    double a = ((sin(lat_difference_radians / 2) * sin(lat_difference_radians / 2)) + (cos(lat1_radians) * cos(lat2_radians) * sin(long_difference_radians / 2) * sin(long_difference_radians / 2)));
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    dist = earth_radius * c;

    return dist;
>>>>>>> 72b969909ea0fa8b59aa0347e24548077742d270
}