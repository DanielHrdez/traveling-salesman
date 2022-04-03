/**
 * @file tsp_greedy.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Tsp Greedy test
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/tsp/tsp_greedy.h"
#include "../tester.h"

void GreedySolve() {
  std::cout << "Greedy Solve" << std::endl;
  // std::vector<Node *> nodes = {
  //   new Node {'A'},
  //   new Node {'B'},
  //   new Node {'C'},
  //   new Node {'D'},
  // };
  // std::vector<Edge> edges = {
  //   Edge {nodes[0], nodes[1], 25},
  //   Edge {nodes[0], nodes[2], 10},
  //   Edge {nodes[0], nodes[3], 15},
  //   Edge {nodes[1], nodes[2], 10},
  //   Edge {nodes[1], nodes[3], 45},
  //   Edge {nodes[2], nodes[3], 5},
  // };
  // Graph graph(edges, nodes);
  // TspGreedy tsp_greedy(graph);

  // std::pair<std::vector<Node *>, int> solution = tsp_greedy.Solve();
  // std::vector<Node *> nodes_solution = solution.first;
  // int cost_solution = solution.second;
  // std::vector<Node *> expected_solution = {
  //   nodes[0],
  //   nodes[2],
  //   nodes[3],
  //   nodes[1],
  //   nodes[0],
  // };
  // int expected_cost = 85;

  // EXPECT_DEEP_EQ(nodes_solution, expected_solution);
  // EXPECT_EQ(cost_solution, expected_cost);
}