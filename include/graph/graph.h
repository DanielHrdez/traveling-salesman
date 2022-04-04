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
    for (int i = 0; i < this->nodes_.size(); i++) {
      this->nodes_[i] = nullptr;
    }
    this->edges_.clear();
  };

  /**
   * @brief Calculate the cost from a node to another
   * 
   * @param from Node from
   * @param to Node to
   * @return int Cost
   */
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

  /**
   * @brief Return the nodes of the graph
   * 
   * @return std::vector<Node *> Nodes
   */
  std::vector<Node *> Nodes() {
    return this->nodes_;
  };

  /**
   * @brief Return the edges of the graph
   * 
   * @return std::vector<Edge> Edges
   */
  std::vector<Edge> Edges() {
    return this->edges_;
  };

  /**
   * @brief Return the number of edges of the graph
   * 
   * @return int Number of edges
   */
  int NumberOfEdges() const {
    return this->edges_.size();
  };

  /**
   * @brief Return the number of nodes of the graph
   * 
   * @return int Number of nodes
   */
  int NumberOfNodes() const {
    return this->nodes_.size();
  };

 private:
  std::vector<Edge> edges_;
  std::vector<Node *> nodes_;
};

#endif // GRAPH_H_
