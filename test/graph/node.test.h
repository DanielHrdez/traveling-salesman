/**
 * @file node.test.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Node test
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/graph/node.h"
#include "../tester.h"
#include <sstream>

void NodeConstructor() {
  std::cout << "NodeConstructor" << std::endl;
  Node node('a');
  EXPECT_EQ(node.Id(), 'a');
  EXPECT_EQ(node.Visited(), false);
}

void NodeOstream() {
  std::cout << "NodeOstream" << std::endl;
  Node *node = new Node('a');
  std::stringstream ss;
  ss << *node;
  EXPECT_EQ(ss.str(), "a");
}
