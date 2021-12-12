#pragma once

#include "HSLAPixel.h"
#include "PNG.h"
#include "graph.h"

using cs225::PNG;
namespace Visual {

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

PNG map_;

// Helper functions
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
    void printEdge(PNG* map, Point src, Point dest);

/**
* @brief Prints all the airports and routes onto a PNG
* @param graph is the output from Dijkstra's
* Perform DFS to traverse the SSSP graph
*/
PNG print(Graph& graph);

/**
* Creates an (x, y) point with a given latitude and longitude coordinate
* Intended to be used in a static context
* @param lat latitude
* @param lon longitude
* @return 2D point (x, y) that represents the latitude and longitude on the map
*/
Point createPoint(double lat, double lon);

}