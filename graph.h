#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Graph {
    public:
// graph-parse.cpp
    Graph();
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
    * @param start index to the starting airport found from locateStart()
    * @return SSSP graph
    */
    Graph* dijkstra(int start);

    private:
    /**
    * Each edge represents a directed and weighted connection between two airports
    * data.first represents the Airport ID of the destination airport
    * data.second represents the distance (weight) from the source airport to this destination airport
    */
    struct Edge {
        std::pair<int, int> data;
        Edge* next;
    };
    std::vector<Edge*> airports;
    int start; // Starting airport
};