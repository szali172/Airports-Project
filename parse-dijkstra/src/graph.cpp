#include "../include/graph.h"
#include <list>
#include <cmath>
#include <math.h>
#include <limits>
#include <queue>

/**
 * @brief when user passes in starting airport name
 * Parses through airports csv file until it finds a matching airport
 * Passed string could be an Airport name or IATA code
 * If no matching string is found, produce an error message
 * @param airports_file csv to parse
 * @param start starting airport to search for
 * @return index of starting airport (Airport ID)
 */
int Graph::locateStart(std::string airports_file, std::string start) {
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
std::vector<Graph::Edge*> Graph::dijkstra(std::vector<Edge*> graph, double start) {   //TODO finish up this function and add useful comments
// Declaring priority queue, priority queue helper for queue operations, and "infinity" integer
    std::priority_queue<Graph::Edge*, std::vector<Graph::Edge*>, Graph::EdgeComparator> pq;
    std::priority_queue<Graph::Edge*, std::vector<Graph::Edge*>, Graph::EdgeComparator> pq_helper;
    int inf = std::numeric_limits<int>::max();

// Printing everything in adjacency list
for (unsigned i = 1; i < adjacency_list.size(); i++) {
  Graph::Edge* neighbor = adjacency_list[i]->next;
  while (neighbor != NULL) {
      neighbor = neighbor->next;
  }
}

// Putting all vertices from adjacency list (main graph structure) into priority queue with distance infinity and prev NULL (except source node will be pushed with distance 0)
    for (unsigned i = 1; i < adjacency_list.size(); i++) {
        if (i != start && adjacency_list[i] == NULL) {
            continue;
        }
        if (i != start) {
            Graph::Edge* pushedge = new Graph::Edge(std::make_pair(i, inf), NULL);
            pq.push(pushedge);
        } else if (i == start && adjacency_list[i] != NULL) {
            Graph::Edge* pushedge = new Graph::Edge(std::make_pair(i, 0), NULL);
            pq.push(pushedge);
        }
    }

 // Shortest path tree to be returned
 std::vector<Graph::Edge*> shortestpath;
 

 // Pushing NULL to every index of shortest path tree to make airport IDs correspond with indices, allowing for O(1) access
 for (unsigned i = 0; i < adjacency_list.size(); i++) {
   shortestpath.push_back(NULL);
 }
 



 for (unsigned i = 1; i < adjacency_list.size(); i++) {

   // Removing minimum element from priority queue
   Graph::Edge* u = pq.top();
   pq.pop();

   // Inserting it into shortest path tree
   shortestpath[u->data.first] = u;
   
   // Going through every neighbor of u, starting at the first neighbor
   Graph::Edge* v = adjacency_list[u->data.first]->next;

    // Check if v (neighbor of u) is in T
    while (v != NULL) {
      // v is already in T
      if (shortestpath[v->data.first] != NULL && adjacency_list[v->data.first] != NULL) {
        v = v->next;
        continue;

      // v is not already in T
      } else if (shortestpath[v->data.first] == NULL && adjacency_list[v->data.first] != NULL) {
        double v_current_distance;
        
        // Search through queue to find v and its distance from the source node
        while (!(pq.empty())) {
          // element was not found
          if (pq.top()->data.first != v->data.first) {
            pq_helper.push(pq.top());
            pq.pop();

            // element was found
          } else {
            v_current_distance = pq.top()->data.second;

            // check if it has smaller distance to source node than distance from current edge u
            if (u->data.second + v->data.second < v_current_distance) {
              // replacing distance
              Graph::Edge* smaller_v = new Graph::Edge(std::make_pair(v->data.first, u->data.second + v->data.second), u);
              pq_helper.push(smaller_v);
              pq.pop();
      
            }
            break;
          }
        }

        // Push everything back to main queue
        while (!(pq_helper.empty())) {
          pq.push(pq_helper.top());
          pq_helper.pop();
        } 
      }
      v = v->next;
    }
 }

 // Making edge connections
 // If a vertex x has previous node y, then vertex y contains x in its edge list 
 for (unsigned i = 1; i < shortestpath.size(); i++) {
   if (shortestpath[i]->prev != NULL) {
     double prev_index = shortestpath[i]->prev->data.first;

     Graph::Edge* curr = shortestpath[prev_index];
     while (curr->next != NULL) {
       curr = curr->next;
     }
     curr->next = new Graph::Edge(std::make_pair(shortestpath[i]->data.first, shortestpath[i]->data.second), NULL);     
   }
 }

 return shortestpath;
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
    // std::cout << "entered calculate distance" << std::endl;
    // getting distance in KILOMETERS
    double dist = -1.0;
    double earth_radius = 6371.0;

    double lat1_radians = latitude1 * (M_PI / 180.0);
    double lat2_radians = latitude2 * (M_PI / 180.0);

    double lon1_radians = longitude1 * (M_PI / 180.0);    //TODO fix this??? (it was commented out originally)
    double lon2_radians = longitude2 * (M_PI / 180.0);    //TODO fix this??? (it was commented out originally)

    double lat_difference_radians = (latitude2 - latitude1) * (M_PI / 180.0);
    double long_difference_radians = (longitude2 - longitude1) * (M_PI / 180.0);

    // setting up a variables a and c for haversine formula
    double a = ((sin(lat_difference_radians / 2.0) * sin(lat_difference_radians / 2.0)) + (cos(lat1_radians) * cos(lat2_radians) * sin(long_difference_radians / 2.0) * sin(long_difference_radians / 2.0)));
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

    dist = earth_radius * c;    // calculates haversine formula to calculate distance between 2 points on earth

    // std::cout << "dist: " << dist << std::endl;

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