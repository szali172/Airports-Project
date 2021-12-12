#include "../include/visual.h"
#include <cmath>

using cs225::PNG;
using cs225::HSLAPixel;
// using Graph::Edge;
using namespace Visual;


/**
* @brief Prints all the airports and routes onto a PNG
* @param graph is the output from Dijkstra's
* Perform DFS to traverse the SSSP graph
*/
PNG Visual::print(Graph& graph, PNG map) {
    PNG* output = new PNG(map); // Create a copy map to draw on

    for (unsigned vertex = 1; vertex < graph.adjacency_list.size(); vertex++) {
        if (graph.adjacency_list[vertex]->label == "UNEXPLORED") {
            print(output, graph, vertex);
        }
    }
    return *output;
}


/**
* Creates an (x, y) Point with a given latitude and longitude coordinate
* @param lat latitude
* @param lon longitude
* @return 2D Point (x, y) that represents the latitude and longitude on the map
*/
Visual::Point Visual::createPoint(PNG* map, double lat, double lon) {
    int x = (int)((map->width()/2) - ((map->width()/2)/180) * abs(lon));
    int y = (int)((map->height()/2) - ((map->height()/2)/90) * abs(lat));

    // If latitude is negative
    if (lat < 0) {
        y = map->height() - y;
    }
    // If longitude is positive
    if (lon > 0) {
        x = map->width() - x;
    }
    x = floor(x);
    y = floor(y);

    Point p(x, y);
    return p;
}


/**
* Helper function to perform DFS
* @param output PNG map to draw on
* @param graph SSSP graph passed from Dijkstra's
* @param vertex index of the airport in the adjacency list
*/
void Visual::print(PNG* output, Graph& graph, int vertex) {
    graph.adjacency_list[vertex]->label = "VISITED";
    Visual::Point src = createPoint(output, graph.adjacency_list[vertex]->data.first, graph.adjacency_list[vertex]->data.second);
    printVertex(output, src);

    Graph::Edge* curr = graph.adjacency_list[vertex]; // curr == head
    if (curr->next != NULL) curr = curr->next; // curr == next adjacent vertex
    else return; // next adjacent vertex does not exist

    while (curr) {
        if (graph.adjacency_list[curr->data.first]->label == "UNEXPLORED") {
            curr->label = "DISCOVERY";
            Point dest = createPoint(output, graph.adjacency_list[curr->data.first]->data.first, graph.adjacency_list[curr->data.first]->data.second);
            printEdge(output, src, dest);
            // Recursive call
            print(output, graph, curr->data.first);
        }
        // Vertex has been already been visited
        // This edge is labeled as a back edge
        else if (curr->label == "UNEXPLORED") {
            curr->label = "BACK";
        }
        curr = curr->next;
    }
}


/**
* Helper function for print()
* prints a red dot on the map to represent the passed airport
* @param map PNG to draw on
* @param airport (x, y) coordinate for the airport
*/
void Visual::printVertex(PNG* map, Visual::Point airport) {
    HSLAPixel pixel;
    pixel.h = 2;
    pixel.s = 0.8;
    pixel.l = 0.47;
    pixel.a = 0.8;
    int x = airport.x;
    int y = airport.y;
    // Change all surrounding pixels to create a circle
    map->getPixel(x, y) = pixel;
    map->getPixel(x - 1, y) = pixel;
    map->getPixel(x + 1, y) = pixel;
    map->getPixel(x, y - 1) = pixel;
    map->getPixel(x, y + 1) = pixel;
    map->getPixel(x - 1, y - 1) = pixel;
    map->getPixel(x - 1, y + 1) = pixel;
    map->getPixel(x + 1, y - 1) = pixel;
    map->getPixel(x + 1, y + 1) = pixel;
    map->getPixel(x - 2, y) = pixel;
    map->getPixel(x + 2, y) = pixel;
    map->getPixel(x, y - 2) = pixel;
    map->getPixel(x, y + 2) = pixel;
}


/**
* Helper function for print()
* prints only the edge from Airport A to B
* @param map PNG to draw on
* @param src source airport
* @param dest destination airport
*/
void Visual::printEdge(PNG* map, Visual::Point src, Visual::Point dest) {
    // Either 0, 1, or -1
    // 0 = still value, 1 = incrementing, -1 = decrementing
    int xMove, yMove = 0;

    if (src.x < dest.x) xMove  = 1;
    else if (src.x > dest.x) xMove = -1;
    
    if (src.y < dest.y) yMove = 1;
    else if (src.y > dest.y) yMove = -1;

    int i = src.x;
    int j = src.y;
    while (i != dest.x && j != dest.y) {
        if (xMove == 1) i++;
        else if (xMove == -1) i--;

        if (yMove == 1) j++;
        else if (yMove == -1) j--;

        HSLAPixel & pixel = map->getPixel(i, j);
        pixel.h = 2;
        pixel.s = 0.8;
        pixel.l = 0.47;
        pixel.a = 0.8;
    }
}