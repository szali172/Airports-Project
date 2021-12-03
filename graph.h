#pragma once

#include "point.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <list>

using namespace cs225;

class Graph {
    public:
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
        Edge* next;
    };

    Graph();

    /**
    * Adds an edge to a Graph
    * @param index index of the vertex the edge will be linked to
    * @param edge edge to be added at that index
    */
    void addEdge(int index, Edge* edge);
    

// graph-parse.cpp
    Graph(std::string airports_file, std::string routes_file);

// print-graph.cpp
    /**
    * Prints all the airports and routes onto a PNG
    * Calls dikstra() and prints the graph returned
    * Perform DFS to traverse the SSSP
    */

    void print() const;

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

    double calculateDistance(double longitude, double latitude);

    private:
    PNG map;
    std::vector<Edge*> adjacency_list;
    int start; // Starting airport
    //std::list<Edge*> adjacency_list[];

    /**
    * Creates an (x, y) point with a given latitude and longitude coordinate
    * @param map used to scale the (x, y) coordinate within the bounds of the image
    * @param lat latitude
    * @param lon longitude
    * @return 2D point (x, y) that represents the latitude and longitude on the map
    */
    Point<2> createPoint(PNG* map, double lat, double lon);

    
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
    void printVertex(PNG* map, Point<2> airport);

    /**
    * Helper function for print()
    * prints only the edge from Airport A to B
    * @param map PNG to draw on
    * @param src source airport
    * @param dest destination airport
    */
    void printEdge(PNG* map, Point<2> src, Point<2> dest);
};