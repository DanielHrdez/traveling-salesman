/**
 * @file tsp_brute_force.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Brute Force class to represent a Brute Force object
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/tsp/tsp_brute_force.h"
#include <climits>
#include <algorithm>

std::pair<std::vector<Node *>, int> TspBruteForce::Solve() {
  std::vector<Node *> nodes = this->graph_.Nodes();
  int min_path = INT_MAX;
  Node *start = nodes[0];
  std::vector<Node *> best_path;
  nodes.erase(nodes.begin());

  do {
    int path = 0;
    Node *current = start;
    for (Node *node : nodes) {
      path += this->graph_.Travel(current, node);
      current = node;
    }
    path += this->graph_.Travel(current, start);
    if (path < min_path) {
      min_path = path;
      best_path.push_back(start);
      best_path = nodes;
      best_path.push_back(start);
    }
  } while (std::next_permutation(nodes.begin(), nodes.end()));

  return { best_path, min_path };
}
