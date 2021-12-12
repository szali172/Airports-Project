#pragma once

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <list>

#include "point.h"

using namespace cs225;

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
            Edge* next;
            Edge(std::pair<double, double> data_, std::string label_) {
                data = data_;
                label = label_;
            }
        };

        /**
         * @brief this is a simple point class which describes
         * a set of 2 points within a 2-dimensional plane. This struct
         * consists of a way to instantiate two integer values as the 2 points,
         * as well as an equals operator to correctly identify if two points are equal
         */
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
        Graph* dijkstra(Graph* graph, int start);

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


        // print-graph.cpp



        /**
        * @brief Prints all the airports and routes onto a PNG
        * Calls dikstra() and prints the graph returned
        * Perform DFS to traverse the SSSP
        * 
        */
        void print();

        /**
        * Creates an (x, y) point with a given latitude and longitude coordinate
        * @param lat latitude
        * @param lon longitude
        * @return 2D point (x, y) that represents the latitude and longitude on the map
        */
        Point createPoint(double lat, double lon);


    private:
        PNG map;    //image which contains the map to visualize the location of every possible airport in the world
        std::vector<Edge*> adjacency_list;  // the adjacency list which contains the verticies and edges of the airports and their location relative to each other
        int start; //the starting airport??? //TODO fix this definition - idk what this is


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
        * @param The variable to be set as the start variable   //TODO fix this param definition - idk what this is
        */
        void setStart(int index);


        /**
        * @brief Creates an (x, y) point with a given latitude and longitude coordinate
        * @param map used to scale the (x, y) coordinate within the bounds of the image
        * @param lat latitude
        * @param lon longitude
        * @return 2D point (x, y) that represents the latitude and longitude on the map
        */
        Point createPoint(PNG* map, double lat, double lon);


        /**
        * Creates an (x, y) Graph::Point with a given latitude and longitude coordinate
        * @param lat latitude
        * @param lon longitude
        * @return 2D Graph::Point (x, y) that represents the latitude and longitude on the map
        */
        Point createPoint(double lat, double lon);

        
        /**
        * @brief Helper function to perform DFS
        * @param output PNG map to draw on
        * @param graph SSSP graph passed from Dijkstra's
        * @param vertex index of the airport in the adjacency list
        */
        void print(PNG* output, Graph& graph, int vertex);


        /**
        * @brief Helper function for print()
        * prints a red dot on the map to represent the passed airport
        * @param map PNG to draw on
        * @param airport (x, y) coordinate for the airport
        */
        void printVertex(PNG* map, Point airport);


        /**
        * @brief Helper function for print()
        * prints only the edge from Airport A to B
        * @param map PNG to draw on
        * @param src source airport
        * @param dest destination airport
        */
        void printEdge(PNG* map, Point src, Point dest);
};