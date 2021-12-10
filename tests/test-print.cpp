#include "../cs225/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

#include "graph.h"
#include "point.h"


using namespace cs225;


/**
* Construct a mini graph to test DFS traversal

* Before traversal:
* [0==NULL]
* [1, "UNEXPLORED"] -> A[<2, 41>, "UNEXPLORED"] -> B[<4, 70>, "UNEXPLORED"]
* [2, "UNEXPLORED"] -> C[<3, 61>, "UNEXPLORED"] -> D[<1, 41>, "UNEXPLORED"] -> E[<5, 71>, "UNEXPLORED"]
* [3, "UNEXPLORED"] -> F[<2, 61>, "UNEXPLORED"] -> G[<7, 22>, "UNEXPLORED"]
* [4, "UNEXPLORED"] -> H[<6, 27>, "UNEXPLORED"]
* [5, "UNEXPLORED"]
* [6, "UNEXPLORED"] -> I[<1, 40>, "UNEXPLORED"] -> J[<5, 21>, "UNEXPLORED"] -> K[<3, 39>, "UNEXPLORED"]
* [7, "UNEXPLORED"] -> L[<5, 34>, "UNEXPLORED"]

* After traversal:
* [0==NULL]
* [1, "VISITED"] -> A[<2, 41>, "DISCOVERY"] -> B[<4, 70>, "DISCOVERY"]
* [2, "VISITED"] -> C[<3, 61>, "DISCOVERY"] -> D[<1, 41>, "BACK"] -> E[<5, 71>, "BACK"]
* [3, "VISITED"] -> F[<2, 61>, "BACK"] -> G[<7, 22>, "DISCOVERY"]
* [4, "VISITED"] -> H[<6, 27>, "DISCOVERY"]
* [5, "VISITED"]
* [6, "VISITED"] -> I[<1, 40>, "BACK"] -> J[<5, 21>, "BACK"] -> K[<3, 39>, BACK"]
* [7, "VISITED"] -> L[<5, 34>, "DISCOVERY"]
*/
TEST_CASE("DFS traversal", "[weight=0][part=3]") {
    Graph dfs();

    // Create vertex list
    dfs.addVertex(NULL);
    dfs.addVertex(Edge one());
    dfs.addVertex(Edge two());
    dfs.addVertex(Edge three());
    dfs.addVertex(Edge four());
    dfs.addVertex(Edge five());
    dfs.addVertex(Edge six());
    dfs.addVertex(Edge seven());

    // Create edge list
    Edge A(); 
    A.data = 
    dfs.addEdge(1, Edge{std::pair<double, double>(2, 41), nullptr});
}


/**
* Construct a graph to traverse for print()
*/
Graph g("airports.csv", "routes.csv");

TEST_CASE("print() Starting Airport as O'Hare", "[weight=0][part=3]") {
  g.setStart(locateStart("ORD"));
  Graph ord = dijkstra(g, g.getStart());



}

