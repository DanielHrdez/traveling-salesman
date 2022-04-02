/**
 * @file edges.test.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Edges class to represent a Edge object
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/graph/edge.h"
#include "../tester.h"

void EdgeConstructor() {
  Node *node_from = new Node();
  Node *node_to = new Node();
  Edge edge(node_from, node_to, 1);
  EXPECT_EQ(edge.Weight(), 1);
  EXPECT_EQ(edge.NodeFrom(), node_from);
  EXPECT_EQ(edge.NodeTo(), node_to);
  delete node_from;
  delete node_to;
}

void ChangeNodes() {
  Node *node_from = new Node();
  Node *node_to = new Node();
  Edge edge1(node_from, node_to, 1);
  Edge edge2(node_from, node_to, 1);
  node_from->name = 'a';
  node_to->name = 'b';
  EXPECT_EQ(edge1.NodeFrom()->name, 'a');
  EXPECT_EQ(edge1.NodeTo()->name, 'b');
  EXPECT_EQ(edge2.NodeFrom()->name, 'a');
  EXPECT_EQ(edge2.NodeTo()->name, 'b');
  delete node_from;
  delete node_to;
}

int main() {
  EdgeConstructor();
  ChangeNodes();
}
