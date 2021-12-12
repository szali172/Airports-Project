#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <cmath>


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
        Edge(std::pair<double, double> data_, std::string label_) {
            data = data_;
            label = label_;
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
    Graph dijkstra(Graph* graph, int start);

    double calculateDistance(double longitude1, double latitude1, double longitude2, double latitude2);

    /**
    * Getter for start member variable
    */
    int getStart();

    /**
    * Setter for private member start
    */
    void setStart(int index);

    std::vector<Edge*> adjacency_list;

    private:
    int start_; // Starting airport

};
