#include "graph.h"

/*
* Prints all the airports and routes onto a PNG
* Calls dikstra() and prints the graph returned
* Perform DFS to traverse the SSSP
*/
void Graph::print() const {
    Graph* SSSP = dijkstra();

    // Initialize the visited map for DFS traversal
    std::vector<bool> visited;
    for (unsigned i = 0; i < SSSP->airports.size(); i++) {
        visited.push_back(false);
    }

    std::stack<Edge*> stack; // Stack for DFS traversal
    stack.push(SSSP->airports[start]); // Queue starting node


}

/**
* Creates an (x, y) point with a given latitude and longitude coordinate
* @param map used to scale the (x, y) coordinate within the bounds of the image
* @param lat latitude
* @param lon longitude
* @return 2D point (x, y) that represents the latitude and longitude on the map
*/
Point<2> Graph::createPoint(PNG* map, double lat, double lon) {
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

    return Point(x, y);
}

/**
* Helper function for print()
* prints a red dot on the map to represent the passed airport
* @param map PNG to draw on
* @param airport (x, y) coordinate for the airport
*/
void Graph::printVertex(PNG* map, Point<2> airport) {
    HSLAPixel & pixel;
    pixel.h = 2;
    pixel.s = 0.8;
    pixel.l = 0.47;
    pixel.a = 0.8;
    int x = airport[0];
    int y = airport[1];
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
void Graph::printEdge(PNG* map, Point<2> src, Point<2> dest) {
    // Either 0, 1, or -1
    // 0 = still value, 1 = incrementing, -1 = decrementing
    int xMove, yMove = 0;

    if (src[0] < dest[0]) xMove  = 1;
    else if (src[0] > dest[0]) xMove = -1;
    
    if (src[1] < dest[1]) yMove = 1;
    else if (src[1] > dest[1]) yMove = -1;

    int i = src[0];
    int j = src[1];
    while (i != dest[0] && j != dest[1]) {
        if (xMove == 1) i++;
        else if (xMove == -1) i--;

        if (yMove == 1) j++;
        else if (yMove == -1) j--;

        HSLAPixel & pixel = map.getPixel(i, j);
        pixel.h = 2;
        pixel.s = 0.8;
        pixel.l = 0.47;
        pixel.a = 0.8;
    }
}