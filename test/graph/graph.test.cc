/**
 * @file graph.test.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Graph test
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/graph/graph.h"
#include "../tester.h"

void Travel() {
  std::cout << "Travel" << std::endl;
  Node *node_from = new Node();
  Node *node_to = new Node();
  Edge edge(node_from, node_to, 1);
  Graph graph = Graph({edge}, {node_from, node_to});
  EXPECT_EQ(graph.Travel(node_from, node_to), 1);
  Node *node_from2 = new Node();
  Node *node_to2 = new Node();
  Edge edge2(node_from2, node_to2, 2);
  graph = Graph({edge, edge2}, {node_from, node_to, node_from2, node_to2});
  EXPECT_EQ(graph.Travel(node_from, node_to), 1);
  EXPECT_EQ(graph.Travel(node_from2, node_to2), 2);
  delete node_from;
}

int main() {
  Travel();
}
