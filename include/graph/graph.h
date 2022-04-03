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
#include <vector>

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
  Graph(std::vector<Edge> edges = {}, std::vector<Node *> nodes = {})
    : edges_(edges), nodes_(nodes) {};

  /**
   * @brief Destroy the Graph object
   * 
   */
  ~Graph() {
    edges_.clear();
    nodes_.clear();
  };

  int Travel(Node *from, Node *to) {
    if (from == to) {
      return 0;
    }
    int distance = 0;
    for (Edge edge : this->edges_) {
      if (edge.NodeFrom() == from && edge.NodeTo() == to ||
          edge.NodeFrom() == to && edge.NodeTo() == from) {
        return edge.Weight();
      }
    }
    return -1;
  };

  std::vector<Node *> Nodes() {
    return this->nodes_;
  };

  std::vector<Edge> Edges() {
    return this->edges_;
  };

  int NumberOfEdges() const {
    return this->edges_.size();
  };

  int NumberOfNodes() const {
    return this->nodes_.size();
  };

 private:
  std::vector<Edge> edges_;
  std::vector<Node *> nodes_;
};

#endif // GRAPH_H_
