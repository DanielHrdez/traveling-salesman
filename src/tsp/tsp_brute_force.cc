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

std::vector<Edge> TspBruteForce::Solve() {
  std::vector<Node *> nodes = this->graph_.Nodes();
  const int kNumberOfNodes = nodes.size();
  const int kNumberOfNodesMinus1 = kNumberOfNodes - 1;
  const int kNumberOfPermutations = this->NumberOfPermutations(kNumberOfNodes);
  std::vector<Edge> best_travel;
  int best_distance = 2147483647;
  int left_index = 1;
  int cost_travel;
  int current_distance;

  nodes.push_back(nodes[0]);
  for (int i = 0; i < kNumberOfPermutations; i++) {
    cost_travel = 0;
    std::vector<Edge> travel;
    for (int j = 0; j < kNumberOfNodesMinus1; j++) {
      current_distance = this->graph_.Travel(nodes[j], nodes[j + 1]);
      cost_travel += current_distance;
      travel.push_back(Edge(nodes[j], nodes[j + 1], current_distance));
    }
    if (cost_travel < best_distance) {
      best_distance = cost_travel;
      best_travel = travel;
    }
    this->SwapNodes(nodes, left_index++, kNumberOfNodesMinus1);
    if (left_index >= kNumberOfNodesMinus1) left_index = 1;
  }
  
  return best_travel;
}

void SwapNodes(std::vector<Node *> &nodes, int i, int j) {
  Node *aux = nodes[i];
  nodes[i] = nodes[j];
  nodes[j] = aux;
}

int TspBruteForce::NumberOfPermutations(int number_of_nodes) {
  if (number_of_nodes <= 1) return 1;
  const int kNumberMinus1 = number_of_nodes - 1;
  return kNumberMinus1 * NumberOfPermutations(kNumberMinus1);
}
