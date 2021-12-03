#pragma once

#include "point.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using namespace cs225;

class Graph {
    public:
    /**
    * Each edge represents a directed and weighted connection between two airports
    * data.first represents the Airport ID of the destination airport
    * data.second represents the distance (weight) from the source airport to this destination airport
    * If the Edge is the head of it's linked list, data.first represents latitude, data.second represents longitude
    */
    struct Edge {
        std::pair<double, double> data;
        Edge* next;
    };

    Graph();

    /**
    * Adds an edge to a Graph
    * @param index index of the vertex edge will be linked to
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
    * Dijkstra's requires two paremeters, a graph and starting node
    *   use "this" to refer to the graph and "start" for the starting node
    * @return SSSP graph
    */
    Graph* dijkstra(Graph graph, int start);

    private:
    std::vector<Edge*> airports;
    int start; // Starting airport

    /**
    * Creates an (x, y) point with a given latitude and longitude coordinate
    * @param map used to scale the (x, y) coordinate within the bounds of the image
    * @param lat latitude
    * @param lon longitude
    * @return 2D point (x, y) that represents the latitude and longitude on the map
    */
    Point<2> createPoint(PNG* map, double lat, double lon);

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