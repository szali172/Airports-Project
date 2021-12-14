#include "catch2/catch.hpp"

#include "../include/graph.h"

TEST_CASE("airports_parse - vertex list only", "[weight=0][part=1]") {
    Graph g("../data/airports.csv");
    REQUIRE(g.adjacency_list.size() != 0);
    std::cout << g.adjacency_list.size() << std::endl;

    // first airport
    REQUIRE(g.adjacency_list[1]->data.first == -6.081689835);
    REQUIRE(g.adjacency_list[1]->data.second == 145.3919983);

    // non-existant airport
    REQUIRE(g.adjacency_list[118] == NULL);

    // O'Hare
    REQUIRE(g.adjacency_list[3830]->data.first == 41.9786);
    REQUIRE(g.adjacency_list[3830]->data.second == -87.9048);
    
    // problematic airport from routes.csv line 171
    REQUIRE(g.adjacency_list[7168] == NULL);

    // last airport
    REQUIRE(g.adjacency_list[14110]->data.first == 46.880001);
    REQUIRE(g.adjacency_list[14110]->data.second == 35.305);
}

TEST_CASE("route parse", "[weight=0][part=[1]") {
    Graph g("../data/airports.csv","../data/routes.csv");
    REQUIRE(g.adjacency_list.size() != 0);
    std::cout << g.adjacency_list.size() << std::endl;
    // std::cout << g.adjacency_list[2965]->data.first << std::endl;
    // std::cout << g.adjacency_list[2965]->data.second << std::endl;
    // std::cout << g.adjacency_list[2965]->next->data.first << std::endl;
}