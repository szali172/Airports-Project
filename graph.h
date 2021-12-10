#pragma once

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <list>
<<<<<<< HEAD
#include <queue>

#include "point.h"
=======
#include <cmath>
>>>>>>> 72b969909ea0fa8b59aa0347e24548077742d270

using namespace cs225;
class Graph {
    public:
    /**
    * Constructs an empty graph
    * Both Vertex and Edge list will be empty
    */
    Graph();

    /**
    * Constructs the Vertex list, but not the Edges
    * Used for Dijkstra's
    */
    Graph(std::string airports_file);

    /**
    * Constructs both Vertex and Edge list
    */
    Graph(std::string airports_file, std::string routes_file);
    
    /**
    * Each edge represents a directed and weighted connection between two airports
    * data.first represents the Airport ID of the destination airport
    * data.second represents the distance (weight) from the source airport to this destination airport
    * label will be used for DFS traversal
    *   Can either be "UNEXPLORED", "DISCOVERY" or "BACK"
    * boolean head will tell us if this current node is the head of it's linked list
    * If the Edge is the head of it's linked list, data.first represents latitude, data.second represents longitude
    */
    struct Edge {
        std::pair<double, double> data;
        std::string label;
        // airport neighbor list is NOT doubly linked - next airport is current airport's next airport, prev is just for the sake of Dijkstra's
        Edge* next;
<<<<<<< HEAD
        Edge* prev;
    };

    class EdgeComparator {
        public:
        double operator()(Edge* edge1, Edge* edge2) {
            return edge1->data.second > edge2->data.second;
=======
        Edge(std::pair<double, double> data_, std::string label_) {
            data = data_;
            label = label_;
>>>>>>> 72b969909ea0fa8b59aa0347e24548077742d270
        }
    };

    struct Point {
        int x;
        int y;
        Point(int x_, int y_) {
            x = x_;
            y = y_;
        }
        bool operator==(Point other) const {
            return this->x == other.x && this->y == other.y;
        }
    };

    /**
    * Adds an edge to a Graph
    * @param index index of the vertex the edge will be linked to
    * @param edge edge to be added at that index
    */
    void addEdge(int index, Edge* edge);
    
    /**
    * Adds a vertex to the adjacency list
    * Pushes vertex to end of the list
    */
    void addVertex(Edge* vertex);
    

// graph-parse.cpp
    void airportParse(std::string airports_file);
    void routeParse(std::string routes_file);

// print-graph.cpp
    /**
    * Prints all the airports and routes onto a PNG
    * Calls dikstra() and prints the graph returned
    * Perform DFS to traverse the SSSP
    */
    void print();

    /**
    * Creates an (x, y) point with a given latitude and longitude coordinate
    * @param lat latitude
    * @param lon longitude
    * @return 2D point (x, y) that represents the latitude and longitude on the map
    */
    Point createPoint(double lat, double lon);


// dijkstra.cpp
    /**
    * Called when user passes in starting airport
    * Parses through airports csv file until it finds a matching airport
    * Passed string could be an Airport name or IATA code
    * If no matching string is found, produce an error message
    * @param airports_file csv to parse
    * @param start starting airport to search for
    * @return index of starting airport (Airport ID)
    */
    int locateStart(std::string airports_file, std::string start);

    /**
    * Performs Dijkstra's algorithm on our directed and weighted graph
    * @param graph perform algorithm on this passed graph
    * @param starting node
    * @return SSSP graph
    */
    Graph* dijkstra(Graph* graph, int start);

    double calculateDistance(double longitude1, double latitude1, double longitude2, double latitude2);

    /**
    * Getter for start member variable
    */
    int getStart();

    private:
    /**
    * Setter for private member start
    */
    void setStart(int index);

// print-graph.cpp helper functions
    
    /**
    * Helper function to perform DFS
    * @param output PNG map to draw on
    * @param graph SSSP graph passed from Dijkstra's
    * @param vertex index of the airport in the adjacency list
    */
    void print(PNG* output, Graph& graph, int vertex);

    /**
    * Helper function for print()
    * prints a red dot on the map to represent the passed airport
    * @param map PNG to draw on
    * @param airport (x, y) coordinate for the airport
    */
    void printVertex(PNG* map, Point airport);

    /**
    * Helper function for print()
    * prints only the edge from Airport A to B
    * @param map PNG to draw on
    * @param src source airport
    * @param dest destination airport
    */
<<<<<<< HEAD
    void printEdge(PNG* map, Point<2> src, Point<2> dest);

    // Queue helper functions

    // Replaces/edits an element in the queue
    void replace(Edge* toReplace, Edge* toInsert);

    // Removes an element from the queue (replace() helper function...?)
    void remove(Edge* element);

    std::vector<Edge*> adjacency_list;
    std::priority_queue<double, std::vector<double>, EdgeComparator> pq;
    int start;
    PNG map;
=======
    void printEdge(PNG* map, Point src, Point dest);
>>>>>>> 72b969909ea0fa8b59aa0347e24548077742d270
};