/**
 * @file tsp_greedy.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Tsp Greedy class
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/tsp/tsp_greedy.h"

std::pair<std::vector<Node *>, int> TspGreedy::Solve() {
  std::vector<Node *> nodes = this->graph_.Nodes();
  std::vector<Node *> solution;
  int cost = 0;
  nodes[0]->SetVisited(true);
  solution.push_back(nodes[0]);
  while (solution.size() < nodes.size()) {
    int min_cost = 2147483647;
    Node *min_node = nullptr;
    for (auto node : nodes) {
      if (!node->Visited()) {
        int cost_travel = this->graph_.Travel(solution.back(), node);
        if (cost_travel < min_cost) {
          min_cost = cost_travel;
          min_node = node;
        }
      }
    }
    min_node->SetVisited(true);
    solution.push_back(min_node);
    cost += min_cost;
  }
  return { solution, cost };
}

