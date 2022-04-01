/**
 * @file graph.hpp
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Graph class to represent a complete undirected graph object
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "edge.h"

/**
 * @brief Graph class to represent a complete undirected graph object
 * 
 */
class Graph {
 public:
  /**
   * @brief Construct a new Graph:: Graph object
   * 
   * @param edges Edges of the graph
   * @param size Size of the graph
   */
  Graph(const Edge *edges, const int number_of_edges, const int number_of_nodes)
    : edges_(edges), number_of_edges_(number_of_edges), number_of_nodes_(number_of_nodes) {};

  /**
   * @brief Destroy the Graph object
   * 
   */
  ~Graph() {
    this->edges_ = nullptr;
  };

  const int NumberOfEdges() const {
    return this->number_of_edges_;
  };

  const int NumberOfNodes() const {
    return this->number_of_nodes_;
  };

 private:
  const Edge *edges_;
  const int number_of_edges_;
  const int number_of_nodes_;
};

#endif // GRAPH_H_
