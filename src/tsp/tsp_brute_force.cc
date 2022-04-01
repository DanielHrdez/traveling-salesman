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

Edge *TspBruteForce::Solve() const {
  const int kIntMax = 2147483647;
  const int kEdges = this->graph_.NumberOfEdges();
  const int kNodes = this->graph_.NumberOfNodes();
  Edge *aux_edges;
  Edge *best_edges;
  int best_distance = kIntMax;
  for (int i = 0; i < kEdges; ++i) {
    aux_edges = this->edges_ + i;
    int distance = aux_edges->Distance();
    if (distance < best_distance) {
      best_distance = distance;
      best_edges = aux_edges;
    }
  }
}
