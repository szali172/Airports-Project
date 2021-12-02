#include "graph.h"

/*
* Prints all the airports and routes onto a PNG
* Calls dikstra() and prints the graph returned
* Perform DFS to traverse the SSSP
*/
void Graph::print() const {
    Graph* SSSP = dijkstra();
    std::stack<Edge*> stack; // Stack for DFS traversal

}

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