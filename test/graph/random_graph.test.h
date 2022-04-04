/**
 * @file random_graph.test.h
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Random Graph test
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/graph/random_graph.h"
#include "../tester.h"

void Generate() {
  std::cout << "Generate" << std::endl;
  RandomGraph random_graph;
  Graph graph = random_graph.Generate(10);
  EXPECT_EQ(graph.NumberOfNodes(), 10);
  EXPECT_EQ(graph.NumberOfEdges(), 45);
}
