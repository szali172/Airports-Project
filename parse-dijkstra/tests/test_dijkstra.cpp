#include "catch2/catch.hpp"
#include "../include/graph.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

TEST_CASE("Locate Starting Airport", "[weight=0][part=1]") {
    Graph g("../data/airports.csv");
    REQUIRE(g.locateStart("../data/airports.csv", "Goroka Airport") == 1);
    REQUIRE(g.locateStart("../data/airports.csv", "Melitopol Air Base") == 14110);
    REQUIRE(g.locateStart("../data/airports.csv", "Paloich Airport, Heliport") == 13714);
    REQUIRE(g.locateStart("../data/airports.csv", "Tarempa Airport") == 7536);
    REQUIRE(g.locateStart("../data/airports.csv", "Chicago O'Hare International Airport") == 3830);
}

TEST_CASE("Calculate Distance", "[weight=0][part=1]") {
  Graph g("../data/airports.csv");
  REQUIRE(g.calculateDistance(-87.9048, 41.9786, -122.308998, 47.449001) == 2891.3567618161); // Chicago O'Hare International Airport -> Seattle Tacoma International Airport
}
