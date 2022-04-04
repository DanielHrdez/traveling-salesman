/**
 * @file main_test.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Main Test File
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "graph/graph.test.h"
#include "graph/node.test.h"
#include "graph/edge.test.h"

#include "io/read_graph.test.h"

#include "tsp/tsp_brute_force.test.h"
#include "tsp/tsp_greedy.test.h"
#include "tsp/tsp_dynamic.test.h"

#include <chrono>

int main() {
  std::cout << "Running all test" << std::endl;

  EdgeConstructor();
  ChangeNodes();

  Travel();

  NodeConstructor();
  NodeOstream();

  BadInputFile();
  NumberOfEdges();
  NodeIn();
  Read();

  BruteSolve();

  GreedySolve();

  DynamicSolve();
  Permutations();
  
  return 0;
}
