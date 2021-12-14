#pragma once

#include "HSLAPixel.h"
#include "PNG.h"
#include "../parse-dijkstra/include/graph.h"
#include "Animation.h"

#include <iostream>
#include <cmath>
#include <utility>

using cs225::PNG;
namespace Visual {

    struct Point {
        int x;
        int y;
        Point(int x_, int y_) {
            x = x_;
            y = y_;
        }
    };

    /**
    * Perform DFS to traverse the SSSP graph
    * @brief Prints all the airports and routes onto a PNG
    * @param graph is the output from Dijkstra's
    * @param map base_map.png to draw from
    * @return pair containing the drawn PNG and the Animation of the DFS traversal
    */
    std::pair<PNG, Animation> visual(Graph& graph, PNG map);

    /**
    * Helper function to perform DFS
    * @param output PNG map to draw on
    * @param graph SSSP graph passed from Dijkstra's
    * @param vertex index of the airport in the adjacency list
    */
    void visual(PNG* output, Graph& graph, int vertex);

    /**
    * Creates an (x, y) point with a given latitude and longitude coordinate
    * Intended to be used in a static context
    * @param map map to get image dimensions from
    * @param lat latitude
    * @param lon longitude
    * @return 2D point (x, y) that represents the latitude and longitude on the map
    */
    Point createPoint(PNG* map, double lat, double lon);


    /**
    * Helper function for visual()
    * prints a red dot on the map to represent the passed airport
    * @param map PNG to draw on
    * @param airport (x, y) coordinate for the airport
    */
    void drawAirport(PNG* map, Point airport);

    /**
    * Helper function for visual()
    * prints only the edge from Airport A to B
    * @param map PNG to draw on
    * @param src source airport
    * @param dest destination airport
    */
    void drawEdge(PNG* map, Point src, Point dest);

    extern Animation animation;
};
