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
  double lat1 = 41.9786;
  double lat2 = 47.449001;
  double long1 = -87.9048;
  double long2 = -122.308998;

  double lat_diff = (lat2 - lat1) * (M_PI / 180.0);
  double long_diff = (long2 - long1) * (M_PI / 180.0);

  double a = ((sin(lat_diff / 2.0) * sin(lat_diff / 2.0)) + (cos(lat1  * (M_PI / 180.0)) * cos(lat2 * (M_PI / 180.0)) * sin(long_diff / 2.0) * sin(long_diff / 2.0)));
  double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

  double dist = 6371.0 * c;

  REQUIRE(g.calculateDistance(long1, lat1, long2, lat2) == dist); // Chicago O'Hare International Airport -> Seattle Tacoma International Airport
}
