/**
 * @file tsp_dynamic.h
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief TSP in dynamic programming
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TSP_DYNAMIC_H_
#define TSP_DYNAMIC_H_

#include "traveling_salesman.h"

class TspDynamic : public TravelingSalesman {
public:
  /**
   * @brief Construct a new Tsp Dynamic object
   * 
   * @param graph Graph of the problem
   */
  TspDynamic(Graph graph = Graph()) : TravelingSalesman(graph) {};

  /**
   * @brief Solve the Traveling Salesman problem by brute force
   * 
   * @return Edge* 
   */
  std::pair<std::vector<Node *>, int> Solve();
  std::vector<std::vector<int>> Permutations(int size);
};

#endif // TSP_DYNAMIC_H_
