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
  std::vector<Node *> nodes = {
    new Node('a'),
    new Node('b'),
    new Node('c'),
    new Node('d'),
  };
  std::vector<Edge> edges = {
    Edge(nodes[0], nodes[1], 1),
    Edge(nodes[0], nodes[2], 2),
    Edge(nodes[0], nodes[3], 3),
    Edge(nodes[1], nodes[2], 4),
    Edge(nodes[1], nodes[3], 5),
    Edge(nodes[2], nodes[3], 6),
  };
  Graph graph(edges, nodes);
  EXPECT_EQ(graph.Travel(nodes[0], nodes[1]), 1);
  EXPECT_EQ(graph.Travel(nodes[0], nodes[2]), 2);
  EXPECT_EQ(graph.Travel(nodes[0], nodes[3]), 3);
  EXPECT_EQ(graph.Travel(nodes[1], nodes[2]), 4);
  EXPECT_EQ(graph.Travel(nodes[1], nodes[3]), 5);
  EXPECT_EQ(graph.Travel(nodes[2], nodes[3]), 6);
  EXPECT_EQ(graph.Travel(nodes[0], nodes[0]), 0);
  EXPECT_EQ(graph.Travel(nodes[1], nodes[1]), 0);
  EXPECT_EQ(graph.Travel(nodes[2], nodes[2]), 0);
  EXPECT_EQ(graph.Travel(nodes[3], nodes[3]), 0);
  EXPECT_EQ(graph.Travel(nodes[1], nodes[0]), 1);
  EXPECT_EQ(graph.Travel(nodes[2], nodes[0]), 2);
  EXPECT_EQ(graph.Travel(nodes[3], nodes[0]), 3);
  EXPECT_EQ(graph.Travel(nodes[2], nodes[1]), 4);
  EXPECT_EQ(graph.Travel(nodes[3], nodes[1]), 5);
  EXPECT_EQ(graph.Travel(nodes[3], nodes[2]), 6);
}
