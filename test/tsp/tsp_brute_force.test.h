/**
 * @file tsp_brute_force.test.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Brute Force tester
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/tsp/tsp_brute_force.h"
#include "../tester.h"

void NumberOfPermutations() {
  std::cout << "NumberOfPermutations" << std::endl;
  TspBruteForce tsp_brute_force;
  EXPECT_EQ(tsp_brute_force.NumberOfPermutations(-1), 1);
  EXPECT_EQ(tsp_brute_force.NumberOfPermutations(0), 1);
  EXPECT_EQ(tsp_brute_force.NumberOfPermutations(1), 1);
  EXPECT_EQ(tsp_brute_force.NumberOfPermutations(2), 1);
  EXPECT_EQ(tsp_brute_force.NumberOfPermutations(3), 2);
  EXPECT_EQ(tsp_brute_force.NumberOfPermutations(4), 6);
  EXPECT_EQ(tsp_brute_force.NumberOfPermutations(5), 24);
}

void SwapNodes() {
  std::cout << "SwapNodes" << std::endl;
  TspBruteForce tsp_brute_force;
  std::vector<Node *> nodes = {
    new Node {'A'},
    new Node {'B'},
    new Node {'C'},
  };
  tsp_brute_force.SwapNodes(nodes, 0, 2);
  EXPECT_EQ(nodes[0]->Id(), 'C');
  EXPECT_EQ(nodes[1]->Id(), 'B');
  EXPECT_EQ(nodes[2]->Id(), 'A');
}

void Solve() {
  std::cout << "Brute Force Solve" << std::endl;
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
  TspBruteForce tsp_brute_force(graph);

  std::pair<std::vector<Node *>, int> solution = tsp_brute_force.Solve();
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
