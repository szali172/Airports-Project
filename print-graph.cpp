#include "graph.h"

/*
* Prints all the airports and routes onto a PNG
* Calls dikstra() and prints the graph returned
* Perform DFS to traverse the SSSP
*/
void Graph::print() {
    Graph* SSSP = dijkstra(this, start);
    PNG* output = new PNG(map); // Create a copy map to draw on

    for (int vertex = 1; vertex < adjacency_list.size(); vertex++) {
        if (adjacency_list[vertex]->label == "UNEXPLORED") {
            print(output, *SSSP, vertex);
        }
    }
}

/**
* Helper function to perform DFS
* @param output PNG map to draw on
* @param graph SSSP graph passed from Dijkstra's
* @param vertex index of the airport in the adjacency list
*/
void Graph::print(PNG* output, Graph& graph, int vertex) {
    graph.adjacency_list[vertex]->label = "VISITED";
    Point<2> src = createPoint(graph.adjacency_list[vertex]->data.first, graph.adjacency_list[vertex]->data.second);
    printVertex(output, src);

    Edge* curr = graph.adjacency_list[vertex]; // curr == head
    if (curr->next != NULL) curr = curr->next; // curr == next adjacent vertex
    else return; // next adjacent vertex does not exist

    while (curr) {
        if (graph.adjacency_list[curr->data.first]->label == "UNEXPLORED") {
            curr->label = "DISCOVERY";
            Point<2> dest = createPoint(graph.adjacency_list[curr->data.first]->data.first, graph.adjacency_list[curr->data.first]->data.second);
            printEdge(output, src, dest);
            // Recursive call
            print(output, graph, curr->data.first)
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
* Creates an (x, y) point with a given latitude and longitude coordinate
* @param lat latitude
* @param lon longitude
* @return 2D point (x, y) that represents the latitude and longitude on the map
*/
Point<2> Graph::createPoint(double lat, double lon) {
    int x = (int)((map.width()/2) - ((map.width()/2)/180) * abs(lon));
    int y = (int)((map.height()/2) - ((map.height()/2)/90) * abs(lat));

    // If latitude is negative
    if (lat < 0) {
        y = map.height() - y;
    }
    // If longitude is positive
    if (lon > 0) {
        x = map.width() - x;
    }

    Point<2> p(x, y);

    return p;
}


/**
* Helper function for print()
* prints a red dot on the map to represent the passed airport
* @param map PNG to draw on
* @param airport (x, y) coordinate for the airport
*/
void Graph::printVertex(PNG* map, Point<2> airport) {
    HSLAPixel pixel;
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

        HSLAPixel & pixel = map->getPixel(i, j);
        pixel.h = 2;
        pixel.s = 0.8;
        pixel.l = 0.47;
        pixel.a = 0.8;
    }
}