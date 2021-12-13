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

        //graph.cpp
        
        /**
        * @brief Each edge represents a directed and weighted connection between two airports
        * data.first represents the Airport ID of the destination airport
        * data.second represents the distance (weight) from the source airport to this destination airport
        * Label will be used for DFS traversal
        *  - Can either be "UNEXPLORED", "DISCOVERY" or "BACK"
        * Boolean head will tell us if this current node is the head of it's linked list
        * If the Edge is the head of it's linked list, data.first represents latitude, data.second represents longitude
        */
        struct Edge {
            std::pair<double, double> data;
            std::string label;
            // airport neighbor list is NOT doubly linked - next airport is current airport's next airport, prev is just for the sake of Dijkstra's
            Edge* next;
            Edge* prev;
            double prev_index;
            //std::list<Edge*>

            Edge(std::pair<double, double> data_, std::string label_) {
                data = data_;
                label = label_;
            }
            Edge(std::pair<double, double> data_, double prev_index_) {
                data = data_;
                prev_index = prev_index_;
            }
        };

        class EdgeComparator {
            public:
                double operator()(Edge* edge1, Edge* edge2) {
                    return edge1->data.second > edge2->data.second;
                }
        };


        /**
        * @brief Constructs an empty graph
        * Both Vertex and Edge list will be empty
        */
        Graph() {};

        /**
        * @brief Called when user passes in starting airport
        * Parses through airports csv file until it finds a matching airport
        * Passed string could be an Airport name or IATA code
        * If no matching string is found, produce an error message
        * @param airports_file csv to parse
        * @param start starting airport to search for
        * @return index of starting airport (Airport ID)
        */
        int locateStart(std::string airports_file, std::string start);

        /**
        * @brief Performs Dijkstra's algorithm on our directed and weighted graph to find the shortest path for a graph using adjacency list
        * @param graph perform algorithm on this passed graph
        * @param starting node
        * @return SSSP graph
        */
        Graph dijkstra(std::vector<Edge*> graph, double start);

        /**
        * @brief Calculates the distance between two coordinates in the world map (2 dimensions, longitude and latitude)
        * 
        * @param longitude1 Longitude of first point
        * @param latitude1 Latitude of first point
        * @param longitude2 Longitude of second point
        * @param latitude2 Latitude of second point
        * @return The distance between two points in kilometers
        */
        double calculateDistance(double longitude1, double latitude1, double longitude2, double latitude2);

        /**
        * @brief Adds an edge to a Graph
        * @param index index of the vertex the edge will be linked to
        * @param edge edge to be added at that index
        */
        void addEdge(int index, Edge* edge);

        /**
        * @brief Adds a vertex to the adjacency list
        * Pushes vertex to end of the list
        * 
        * @param vertex the vertex to be pushed to the end of the adjacency list
        */
        void addVertex(Edge* vertex);


        // graph-parse.cpp

        /**
        * @brief Constructs the Vertex list, but not the Edges
        * Used for Dijkstra's
        * 
        * @param airports_file CSV file containing all the airports and their specific location in the world (latitude and longitude in 2d space)
        */
        Graph(std::string airports_file);

        /**
        * @brief Constructs both Vertex and Edge list
        * Used for Dijkstra's
        * 
        * @param airports_file CSV file containing all the airports and their specific location in the world (latitude and longitude in 2d space)
        * @param routes_file CSV file containing all the possible routes between 2 different airports
        */
        Graph(std::string airports_file, std::string routes_file);

        // SET ADJACENCY LIST
        Graph(std::vector<Edge*> adj_list) {
            adjacency_list = adj_list;
        }

        std::vector<Edge*> adjacency_list;  // the adjacency list which contains the verticies and edges of the airports and their location relative to each other


    private:
        int start_; //the starting airport??? //TODO fix this definition - idk what this is
        //std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparator> pq;

        //graph-parse.cpp


        /**
        * @brief Private helper function for the Graph constructor (both the one parameter and two parameter constructors)
        * Constructs the Vertex list, but not the Edges
        * Used for Dijkstra's
        * Constructs the vertexes adjacency list by filling in all the information from the CSV file
        * @param airports_file CSV file containing all the airports and their specific location in the world (latitude and longitude in 2d space)
        */
        void airportParse(std::string airports_file);


        /**
        * @brief Private helper function for the Graph constructor (only for the two parameter constructors)
        * Constructs the Edges list, but not the Vertex list (is required to be constructed before calling the routes [this] function)
        * Used for Dijkstra's
        * Constructs the vertexes adjacency list by filling in all the information from the CSV file
        * @param routes_file CSV file containing all the possible routes between 2 different airports
        */
        void routeParse(std::string routes_file);


        /**
        * @brief Setter for private member start //TODO fix this definition - idk what this is
        * @param index variable to be set as the start variable   //TODO fix this param definition - idk what this is
        */
        void setStart(int index);

    
};
