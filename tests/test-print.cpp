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
* Construct a graph to traverse for print()
*/
Graph g("airports.csv", "routes.csv");

TEST_CASE("DFS traversal", "[weight=0][part=3]") {
    Graph dfs();
    dfs.addVertex()
}

TEST_CASE("print() Starting Airport as O'Hare", "[weight=0][part=3]") {
  g.setStart(locateStart("ORD"));
  Graph ord = dijkstra(g, g.getStart());



}

