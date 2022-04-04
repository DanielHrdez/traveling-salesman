/**
 * @file tsp_greedy.h
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Greedy class to represent a Tsp Greedy object
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TSP_GREEDY_H_
#define TSP_GREEDY_H_

#include "traveling_salesman.h"

class TspGreedy : public TravelingSalesman {
 public:
  /**
   * @brief Construct a new Tsp Brute Force object
   * 
   * @param graph Graph of the problem
   */
  TspGreedy(Graph graph = Graph()) : TravelingSalesman(graph) {};

  /**
   * @brief Solve the Traveling Salesman problem by brute force
   * 
   * @return Edge* 
   */
  std::pair<std::vector<Node *>, int> Solve();
};

#endif // TSP_GREEDY_H_
