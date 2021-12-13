#include "../include/visual.h"


using cs225::PNG;
using cs225::HSLAPixel;
// using Graph::Edge;
namespace Visual {

    Animation animation;
    /**
    * @brief Prints all the airports and routes onto a PNG
    * @param graph is the output from Dijkstra's
    * Perform DFS to traverse the SSSP graph
    */
    std::pair<PNG, Animation> visual(Graph& graph, PNG map) {
        animation.addFrame(map); // Add blank image as first frame for animation
        PNG* output = new PNG(map); // Create a copy map to draw on


        for (unsigned vertex = 1; vertex < graph.adjacency_list.size(); vertex++) {
            if (graph.adjacency_list[vertex]->label == "UNEXPLORED") {
                visual(output, graph, vertex);
            }
        }
        return std::pair<PNG, Animation>(*output, animation);
    }


    /**
    * Helper function to perform DFS
    * @param output PNG map to draw on
    * @param graph SSSP graph passed from Dijkstra's
    * @param vertex index of the airport in the adjacency list
    */
    void visual(PNG* output, Graph& graph, int vertex) {
        graph.adjacency_list[vertex]->label = "VISITED";
        Visual::Point src = createPoint(output, graph.adjacency_list[vertex]->data.first, graph.adjacency_list[vertex]->data.second);
        drawAirport(output, src);

        Graph::Edge* curr = graph.adjacency_list[vertex]; // curr == head
        if (curr->next != NULL) curr = curr->next; // curr == next adjacent vertex
        else return; // next adjacent vertex does not exist

        while (curr) {
            if (graph.adjacency_list[curr->data.first]->label == "UNEXPLORED") {
                curr->label = "DISCOVERY";
                Point dest = createPoint(output, graph.adjacency_list[curr->data.first]->data.first, graph.adjacency_list[curr->data.first]->data.second);
                drawEdge(output, src, dest);
                // Recursive call
                visual(output, graph, curr->data.first);
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
    * Creates an (x, y) Point with a given latitude and longitude coordinate
    * @param lat latitude
    * @param lon longitude
    * @return 2D Point (x, y) that represents the latitude and longitude on the map
    */
    Point createPoint(PNG* map, double lat, double lon) {
        
        long double x = ((map->width()/2.0) - ((map->width()/2.0)/180.0) * std::abs(lon));
        long double y = ((map->height()/2.0) - ((map->height()/2.0)/90.0) * std::abs(lat));

        // If latitude is negative
        if (lat < 0) {
            y = double(map->height()) - y;
        }
        // If longitude is positive
        if (lon > 0) {
            x = double(map->width()) - x;
        }

        x = round(x);
        y = round(y);

        Point p(x, y);
        return p;
    }

    /**
    * Helper function for visual()
    * prints a red dot on the map to represent the passed airport
    * @param map PNG to draw on
    * @param airport (x, y) coordinate for the airport
    */
    void drawAirport(PNG* map, Point airport) {
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
    * Helper function for visual()
    * prints only the edge from Airport A to B
    * @param map PNG to draw on
    * @param src source airport
    * @param dest destination airport
    */
    void drawEdge(PNG* map, Visual::Point src, Visual::Point dest) {
        // Either 0, 1, or -1
        // 0 = still value, 1 = incrementing, -1 = decrementing
        int xMove, yMove = 0;

        if (src.x < dest.x) xMove  = 1;
        else if (src.x > dest.x) xMove = -1;
        
        if (src.y < dest.y) yMove = 1;
        else if (src.y > dest.y) yMove = -1;

        int i = src.x;
        int j = src.y;
        int frameInterval = 0; // Every 10 frameIntervals add current PNG state to animation
        while (i != dest.x && j != dest.y) {
            if (frameInterval % 10 == 0) {
                animation.addFrame(*map);
            }
            if (xMove == 1) i++;
            else if (xMove == -1) i--;

            if (yMove == 1) j++;
            else if (yMove == -1) j--;

            HSLAPixel & pixel = map->getPixel(i, j);
            pixel.h = 2;
            pixel.s = 0.8;
            pixel.l = 0.47;
            pixel.a = 0.8;
            frameInterval++;
        }
    }
}