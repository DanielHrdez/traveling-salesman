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
   */
  Graph(Edge* edges) : edges_(edges) {};

  /**
   * @brief Destroy the Graph object
   * 
   */
  ~Graph() {
    this->edges_ = nullptr;
  };

 private:
  Edge* edges_;
};

#endif // GRAPH_H_
