/**
 * @file tsp_dynamic.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief TSP in dynamic programming
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/tsp/tsp_dynamic.h"
#include <climits>

std::pair<std::vector<Node *>, int> TspDynamic::Solve() {
  std::vector<Node *> nodes = this->graph_.Nodes();
  nodes[0]->Visited(true);
  int min_path = INT_MAX;
  return TspDynamic::Solve(nodes, 0, nodes.size(), 1, 0, min_path);
}

std::pair<std::vector<Node *>, int> TspDynamic::Solve(
  std::vector<Node *> nodes,
  int current_position,
  int number_of_nodes,
  int count,
  int cost,
  int &min_path
) {
  if (count == number_of_nodes) {
    if (cost + this->graph_.Travel(nodes[current_position], nodes[0]) < min_path) {
      min_path = cost + this->graph_.Travel(nodes[current_position], nodes[0]);
      std::vector<Node *> solution;
      solution.push_back(nodes[current_position]);
      for (int i = 0; i < number_of_nodes; i++) {
        if (nodes[i]->Visited()) {
          solution.push_back(nodes[i]);
        }
      }
      solution.push_back(nodes[0]);
      return { solution, min_path };
    } else {
      return { {}, min_path };
    }
  }
  for (int i = 0; i < number_of_nodes; i++) {
    if (!nodes[i]->Visited()) {
      nodes[i]->Visited(true);
      std::pair<std::vector<Node *>, int> result = TspDynamic::Solve(
        nodes,
        i,
        number_of_nodes,
        count + 1,
        cost + this->graph_.Travel(nodes[current_position], nodes[i]),
        min_path
      );
      if (result.second < min_path) {
        min_path = result.second;
        return result;
      }
      nodes[i]->Visited(false);
    }
  }
  return { {}, min_path };
}
