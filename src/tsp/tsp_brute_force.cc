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
  // const int kIntMax = 2147483647;
  // const int kEdges = this->graph_.NumberOfEdges();
  // const int kNodes = this->graph_.NumberOfNodes();
  // std::vector<Edge> aux_edges;
  // std::vector<Edge> best_edges;
  // int best_distance = kIntMax;

  // for (Edge egde : this->graph_.Edges()) {
  //   edge.
  // }
}
  
std::vector<std::vector<Edge>> TspBruteForce::Permutacions(std::vector<Node *> nodes) {
  const int kNumberOfPermutations = this->NumberOfPermutations(nodes.size());
  std::vector<std::vector<Edge>> permutations;
  nodes.push_back(nodes[0]);
  for (int i = 0; i < kNumberOfPermutations; i++) {
    std::vector<Edge> permutation;
    for (int j = 0; j < nodes.size() - 1; j++) {
      permutation.push_back(Edge(nodes[j], nodes[j + 1], this->graph_.Travel(nodes[j], nodes[j + 1])));
    }
    permutations.push_back(permutation);

  }
}

int TspBruteForce::NumberOfPermutations(int number_of_nodes) {
  if (number_of_nodes <= 1) return 1;
  const int kNumberMinus1 = number_of_nodes - 1;
  return kNumberMinus1 * NumberOfPermutations(kNumberMinus1);
}
