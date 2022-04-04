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
   * @brief Solve the Traveling Salesman problem by dynamic programming
   * 
   * @return Edge* 
   */
  std::pair<std::vector<Node *>, int> Solve();

 private:
  /**
   * @brief Solve the Traveling Salesman problem by dynamic programming
   * 
   * @param nodes Nodes of the graph
   * @param current_position Current position of the salesman
   * @param number_of_nodes Number of nodes of the graph
   * @param count Number of nodes visited
   * @param cost Cost of the path
   * @param min_path Minimum cost of the path
   * 
   * @return std::pair<std::vector<Node *>, int> The solution and the minimum cost
   */
  std::pair<std::vector<Node *>, int> Solve(
    std::vector<Node *> nodes,
    int current_position,
    int number_of_nodes,
    int count,
    int cost,
    int &min_path
  );
};

#endif // TSP_DYNAMIC_H_
