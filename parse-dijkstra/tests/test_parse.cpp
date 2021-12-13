#include "catch2/catch.hpp"

#include "../include/graph.h"

TEST_CASE("airports_parse - vertex list only", "[weight=0][part=1]") {
    Graph g("../data/airports.csv");
    REQUIRE(g.adjacency_list.size() != 0);
    std::cout << g.adjacency_list.size() << std::endl;
    
    
}

TEST_CASE("route parse", "[weight=0][part=[1]") {
    Graph g("../data/routes.csv");
    REQUIRE(g.adjacency_list.size() != 0);
    std::cout << g.adjacency_list.size() << std::endl;
}