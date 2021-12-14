 #include "catch2/catch.hpp"

// https://github.com/catchorg/Catch2/blob/devel/docs/own-main.md#top

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "graph.h"
#include "../include/PNG.h"
#include "../include/HSLAPixel.h"
#include "../include/visual.h"

#include <unistd.h>

using namespace cs225;
using namespace Visual;

TEST_CASE("Lat-Lon to pixel formula", "[weight=0][part=3]") {
  std::cout << "Entered Test" << std::endl;
  Graph g;
  std::cout << "Created Graph" << std::endl;
  PNG png;
  PNG* map = &png;
  std::cout << "Created PNG" << std::endl;
  map->readFromFile("../data/base_map.png");
  std::cout << map->width() << std::endl;
  std::cout << "Read from file" << std::endl;
  Point p = createPoint(map, 10, 67.34);
  REQUIRE(p.x == 3435);
  REQUIRE(p.y == 1111);
  p = createPoint(map, -45.33, -10);
  REQUIRE(p.x == 2361);
  REQUIRE(p.y == 1880);
  p = createPoint(map, 90, 180); // Top-Right Corner
  REQUIRE(p.x == 5000);
  REQUIRE(p.y == 0); 
  p = createPoint(map, -90, -180); // Bottom-Left Corner
  REQUIRE(p.x == 0);
  REQUIRE(p.y == 2500);
  p = createPoint(map, 0, 0); // Center
  REQUIRE(p.x == 2500);
  REQUIRE(p.y == 1250); 
}



////////////////////////////////////////////////////////
/**
 * Copy of visual() functions in visual.h
 * Will solely perform DFS without editing any PNG's
 * Created to test the traversal and ensure the proper order
 */
void DFS(Graph& graph);
void DFS(Graph& graph, int vertex);

void DFS(Graph& graph) {
    for (unsigned vertex = 1; vertex < graph.adjacency_list.size(); vertex++) {
        if (graph.adjacency_list[vertex]->label == "UNEXPLORED") {
            DFS(graph, vertex);
        }
    }
}

void DFS(Graph& graph, int vertex) {
    graph.adjacency_list[vertex]->label = "VISITED";
    std::cout << "Vertex " << vertex << " == " << graph.adjacency_list[vertex]->label << std::endl;
    //Visual::Point src = createPoint(output, graph.adjacency_list[vertex]->data.first, graph.adjacency_list[vertex]->data.second);
    //printVertex(output, src);

    Graph::Edge* curr = graph.adjacency_list[vertex]; // curr == head
    if (curr->next != NULL) {
      //std::cout << "Entered curr->next != NULL" << std::endl; 
      curr = curr->next;  // curr == next adjacent vertex 
    } else {
      std::cout << "curr->next == NULL, returning..." << std::endl;
      return; // next adjacent vertex does not exist
    }
    while (curr) {
      std::cout << "index: " << vertex << std::endl;
      std::cout << "Curr: " << curr->data.first << ", " << curr->data.second << " | " << curr->label << std::endl;
      if (graph.adjacency_list[curr->data.first]->label == "UNEXPLORED") {
          curr->label = "DISCOVERY";
          std::cout << "->Curr: " << curr->data.first << ", " << curr->data.second << " | " << curr->label << std::endl;
          //Point dest = createPoint(output, graph.adjacency_list[curr->data.first]->data.first, graph.adjacency_list[curr->data.first]->data.second);
          //printEdge(output, src, dest);
          // Recursive call
          DFS(graph, curr->data.first);
      }
      // Vertex has been already been visited
      // This edge is labeled as a back edge
      else if (curr->label == "UNEXPLORED") {
          curr->label = "BACK";
          std::cout << "->Curr: " << curr->data.first << ", " << curr->data.second << " | " << curr->label << std::endl;
      }
      //std::cout << "Vertex == " << vertex << std::endl;
      std::cout << "CURR = CURR->NEXT" << std::endl;
      curr = curr->next;
    }
}

//////////////////////////////////////////////////




// /**
// * Construct a mini graph to test DFS traversal

// * Before traversal:
// * [0==NULL]
// * [1, "UNEXPLORED"] -> A[<2, 41>, "UNEXPLORED"] -> B[<4, 70>, "UNEXPLORED"]
// * [2, "UNEXPLORED"] -> C[<3, 61>, "UNEXPLORED"] -> D[<1, 41>, "UNEXPLORED"] -> E[<5, 71>, "UNEXPLORED"]
// * [3, "UNEXPLORED"] -> F[<2, 61>, "UNEXPLORED"] -> G[<7, 22>, "UNEXPLORED"]
// * [4, "UNEXPLORED"] -> H[<6, 27>, "UNEXPLORED"]
// * [5, "UNEXPLORED"]
// * [6, "UNEXPLORED"] -> I[<1, 40>, "UNEXPLORED"] -> J[<5, 21>, "UNEXPLORED"] -> K[<3, 39>, "UNEXPLORED"]
// * [7, "UNEXPLORED"] -> L[<5, 34>, "UNEXPLORED"]

// * After traversal:
// * [0==NULL]
// * [1, "VISITED"] -> A[<2, 41>, "DISCOVERY"] -> B[<4, 70>, "DISCOVERY"]
// * [2, "VISITED"] -> C[<3, 61>, "DISCOVERY"] -> D[<1, 41>, "BACK"] -> E[<5, 71>, "BACK"]
// * [3, "VISITED"] -> F[<2, 61>, "BACK"] -> G[<7, 22>, "DISCOVERY"]
// * [4, "VISITED"] -> H[<6, 27>, "DISCOVERY"]
// * [5, "VISITED"]
// * [6, "VISITED"] -> I[<1, 40>, "BACK"] -> J[<5, 21>, "BACK"] -> K[<3, 39>, BACK"]
// * [7, "VISITED"] -> L[<5, 34>, "DISCOVERY"]
// */
TEST_CASE("DFS traversal", "[weight=0][part=3]") {
  Graph dfs;
  Graph::Edge one(std::pair<double, double>(-0.33, 0.5), "UNEXPLORED");
  Graph::Edge two(std::pair<double, double>(0.33, 0.5), "UNEXPLORED");
  Graph::Edge three(std::pair<double, double>(0.33, -0.5), "UNEXPLORED");
  Graph::Edge four(std::pair<double, double>(-0.33, -0.5), "UNEXPLORED");
  Graph::Edge five(std::pair<double, double>(-0.33, 0.7), "UNEXPLORED");
  Graph::Edge six(std::pair<double, double>(-0.34, 0.5), "UNEXPLORED");
  Graph::Edge seven(std::pair<double, double>(-0.13, 0.5), "UNEXPLORED");

  // std::cout << one.next << std::endl;
  // std::cout << two.next << std::endl;
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
  for (unsigned i = 1; i < dfs.adjacency_list.size(); i++) {
    std::cout << "[" << i << "]";
    Graph::Edge* curr = dfs.adjacency_list[i];
    while (curr->next != NULL) {
      curr = curr->next;
      std::cout << " -> [" << curr->data.first << ", " << curr->data.second << "]";
    } 
    std::cout << std::endl;
  }
  DFS(dfs);
  std::cout << dfs.adjacency_list.size() << std::endl;

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
* Construct a graph to traverse for visual()
*/


TEST_CASE("Visual - Draw entire data", "[weight=0][part=3]") {
  Graph g("../data/airports.csv", "../data/routes.csv");
  std::cout << g.adjacency_list.size() << std::endl;
  PNG png;
  PNG* map = &png;
  map->readFromFile("../data/base_map.png");
  std::cout << map->width() << std::endl;

  std::cout << "Airport 2030: " << g.adjacency_list[2030]->data.first << ", " << g.adjacency_list[2030]->data.second << std::endl;

//   std::pair<PNG, Animation> output;
  PNG output = Visual::visual(g, *map);
  std::cout << "COMPLETED VISUAL()" << std::endl;
  HSLAPixel red;
  red.h = 2;
  red.s = 0.8;
  red.l = 0.47;
  red.a = 0.8;

  for (unsigned i = 1; i < g.adjacency_list.size(); i++) {
      if (g.adjacency_list[i] != NULL) {
        Visual::Point p = Visual::createPoint(map, g.adjacency_list[i]->data.first, g.adjacency_list[i]->data.second);
        REQUIRE(output.getPixel(p.x, p.y) == red);
      }
  }
  output.writeToFile("output.png");
}
