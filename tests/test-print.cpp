#include "../cs225/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../graph.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

using namespace cs225;

TEST_CASE("Lat-Lon to pixel formula", "[weight=0][part=3]") {
  Graph g;
  REQUIRE(g.createPoint(10, 67.34) == Graph::Point(3435, 1111));
  REQUIRE(g.createPoint(-45.33, -10) == Graph::Point(1870, 1388));
  REQUIRE(g.createPoint(90, 180) == Graph::Point(5000, 0)); // Top-Right Corner
  REQUIRE(g.createPoint(-90, -180) == Graph::Point(0, 2500)); // Bottom-Left Corner
  REQUIRE(g.createPoint(0, 0) == Graph::Point(2500, 1250)); // Center
}

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
    Graph dfs;
    PNG png; // Blank PNG to pass into DFS function, Will not be edited or returned

    Graph::Edge one(std::pair<double, double>(-0.33, 0.5), "UNEXPLORED");
    Graph::Edge two(std::pair<double, double>(0.33, 0.5), "UNEXPLORED");
    Graph::Edge three(std::pair<double, double>(0.33, -0.5), "UNEXPLORED");
    Graph::Edge four(std::pair<double, double>(-0.33, -0.5), "UNEXPLORED");
    Graph::Edge five(std::pair<double, double>(-0.33, 0.7), "UNEXPLORED");
    Graph::Edge six(std::pair<double, double>(-0.34, 0.5), "UNEXPLORED");
    Graph::Edge seven(std::pair<double, double>(-0.13, 0.5), "UNEXPLORED");

    // Create vertex list
    dfs.addVertex(NULL);
    dfs.addVertex(&one);
    dfs.addVertex(&two);
    dfs.addVertex(&three);
    dfs.addVertex(&four);
    dfs.addVertex(&five);
    dfs.addVertex(&six);
    dfs.addVertex(&seven);

    // Create edge list
    Graph::Edge A(std::pair<double, double>(2, 41), "UNEXPLORED");
    Graph::Edge B(std::pair<double, double>(4, 70), "UNEXPLORED");
    Graph::Edge C(std::pair<double, double>(3, 61), "UNEXPLORED");
    Graph::Edge D(std::pair<double, double>(1, 41), "UNEXPLORED");
    Graph::Edge E(std::pair<double, double>(5, 71), "UNEXPLORED");
    Graph::Edge F(std::pair<double, double>(2, 61), "UNEXPLORED");
    Graph::Edge G(std::pair<double, double>(7, 22), "UNEXPLORED");
    Graph::Edge H(std::pair<double, double>(6, 27), "UNEXPLORED");
    Graph::Edge I(std::pair<double, double>(1, 40), "UNEXPLORED");
    Graph::Edge J(std::pair<double, double>(5, 21), "UNEXPLORED");
    Graph::Edge K(std::pair<double, double>(3, 39), "UNEXPLORED");
    Graph::Edge L(std::pair<double, double>(5, 34), "UNEXPLORED");

    dfs.addEdge(1, &B);
    dfs.addEdge(1, &A);
    dfs.addEdge(2, &E);
    dfs.addEdge(2, &D);
    dfs.addEdge(2, &C);
    dfs.addEdge(3, &G);
    dfs.addEdge(3, &F);
    dfs.addEdge(4, &H);
    dfs.addEdge(6, &K);
    dfs.addEdge(6, &J);
    dfs.addEdge(6, &I);
    dfs.addEdge(7, &L);

    // Call function to perform DFS
    //TODO print(png, dfs, 1);

    // Make sure all vertices have been visited
    REQUIRE(one.label == "VISITED");
    REQUIRE(two.label == "VISITED");
    REQUIRE(three.label == "VISITED");
    REQUIRE(four.label == "VISITED");
    REQUIRE(five.label == "VISITED");
    REQUIRE(six.label == "VISITED");
    REQUIRE(seven.label == "VISITED");

    // Starting at Vertex one, specific Graph::Edges will either "DISCOVERY" or "BACK"
    REQUIRE(A.label == "DISCOVERY");
    REQUIRE(B.label == "DISCOVERY");
    REQUIRE(C.label == "DISCOVERY");
    REQUIRE(D.label == "BACK");
    REQUIRE(E.label == "BACK");
    REQUIRE(F.label == "BACK");
    REQUIRE(G.label == "DISCOVERY");
    REQUIRE(H.label == "DISCOVERY");
    REQUIRE(I.label == "BACK");
    REQUIRE(J.label == "BACK");
    REQUIRE(K.label == "BACK");
    REQUIRE(L.label == "DISCOVERY");
}


/**
* Construct a graph to traverse for print()
*/
Graph g("airports.csv", "routes.csv");

TEST_CASE("print() Starting Airport as O'Hare", "[weight=0][part=3]") {
  //TODO g.setStart(locateStart("ORD"));
  //TODO Graph ord = g.dijkstra(g, g.getStart());

}
