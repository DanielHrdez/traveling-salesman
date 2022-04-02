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
  Graph(Edge **edges, int number_of_edges, int number_of_nodes)
    : edges_(edges), number_of_edges_(number_of_edges), number_of_nodes_(number_of_nodes) {};

  /**
   * @brief Destroy the Graph object
   * 
   */
  ~Graph() {
    this->edges_ = nullptr;
  };

  int NumberOfEdges() const {
    return this->number_of_edges_;
  };

  int NumberOfNodes() const {
    return this->number_of_nodes_;
  };

 private:
  Edge **edges_;
  int number_of_edges_;
  int number_of_nodes_;
};

#endif // GRAPH_H_
