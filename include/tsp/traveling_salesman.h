/**
 * @file traveling_salesman.hpp
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Framework for the Traveling Salesman problem
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TRAVELING_SALESMAN_H_
#define TRAVELING_SALESMAN_H_

#include "../graph/graph.h"

class TravelingSalesman {
 public:
  /**
   * @brief Construct a new Traveling Salesman object
   * 
   * @param graph Graph of the problem
   */
  TravelingSalesman(Graph graph) : graph_(graph) {};

  /**
   * @brief Destroy the Traveling Salesman object
   * 
   */
  virtual ~TravelingSalesman() {};

  /**
   * @brief Solve the Traveling Salesman problem
   * 
   * @return Edge* 
   */
  virtual std::vector<Edge> Solve() const = 0;

 protected:
  Graph graph_;
};

#endif // TRAVELING_SALESMAN_H_
