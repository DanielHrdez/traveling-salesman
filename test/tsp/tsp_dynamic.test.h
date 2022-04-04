/**
 * @file tsp_dynamic.test.h
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief TSP in dynamic programming TEST
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/tsp/tsp_dynamic.h"
#include "../tester.h"

void DynamicSolve() {
  std::cout << "Dynamic Solve" << std::endl;
  std::vector<Node *> nodes = {
    new Node {'A'},
    new Node {'B'},
    new Node {'C'},
    new Node {'D'},
  };
  std::vector<Edge> edges = {
    Edge {nodes[0], nodes[1], 25},
    Edge {nodes[0], nodes[2], 10},
    Edge {nodes[0], nodes[3], 15},
    Edge {nodes[1], nodes[2], 10},
    Edge {nodes[1], nodes[3], 45},
    Edge {nodes[2], nodes[3], 5},
  };
  Graph graph(edges, nodes);
  TspDynamic tsp_dynamic(graph);

  std::pair<std::vector<Node *>, int> solution = tsp_dynamic.Solve();
  std::vector<Node *> nodes_solution = solution.first;
  int cost_solution = solution.second;
  std::vector<Node *> expected_solution = {
    nodes[0],
    nodes[1],
    nodes[2],
    nodes[3],
    nodes[0],
  };
  int expected_cost = 55;

  EXPECT_DEEP_EQ(nodes_solution, expected_solution);
  EXPECT_EQ(cost_solution, expected_cost);
}

void Permutations() {
  std::cout << "Permutations" << std::endl;
  std::vector<Node *> nodes = {
    new Node {'A'},
    new Node {'B'},
    new Node {'C'},
    new Node {'D'},
  };
  std::vector<Edge> edges = {
    Edge {nodes[0], nodes[1], 25},
    Edge {nodes[0], nodes[2], 10},
    Edge {nodes[0], nodes[3], 15},
    Edge {nodes[1], nodes[2], 10},
    Edge {nodes[1], nodes[3], 45},
    Edge {nodes[2], nodes[3], 5},
  };
  Graph graph(edges, nodes);
  TspDynamic tsp_dynamic(graph);

  std::vector<std::vector<int>> permutations = tsp_dynamic.Permutations(4);
  std::vector<std::vector<int>> expected_permutations = {
    {0, 1, 2, 3},
    {0, 1, 3, 2},
    {0, 2, 1, 3},
    {0, 2, 3, 1},
    {0, 3, 1, 2},
    {0, 3, 2, 1},
  };

  EXPECT_DEEP_EQ(permutations, expected_permutations);
}
