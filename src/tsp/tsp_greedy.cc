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
#include <climits>

std::pair<std::vector<Node *>, int> TspGreedy::Solve() {
  std::vector<Node *> nodes = this->graph_.Nodes();
  const int kNumberOfNodes = nodes.size();
  std::vector<Node *> solution;
  int cost = 0;
  nodes[0]->Visited(true);
  solution.push_back(nodes[0]);

  while (solution.size() < kNumberOfNodes) {
    int min_cost = INT_MAX;
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
    min_node->Visited(true);
    solution.push_back(min_node);
    cost += min_cost;
  }

  cost += this->graph_.Travel(solution.back(), solution[0]);
  solution.push_back(solution[0]);
  return { solution, cost };
}

