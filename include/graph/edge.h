/**
 * @file edges.hpp
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Edges class to represent a Edge object
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef EDGE_H_
#define EDGE_H_

#include "node.h"

/**
 * @brief class to represent an Edge object
 * 
 */
class Edge {
 public:
  /**
   * @brief Construct a new Edge:: Edge object
   *
   *
   */
  Edge() {};

  /**
   * @brief Construct a new Edge object
   * 
   * @param from Node from
   * @param to Node to
   * @param weight Weight from node to node
   */
  Edge(Node *node_from, Node *node_to, int weight)
    : node_from_(node_from), node_to_(node_to), weight_(weight) {};

  /**
   * @brief Destroy the Edges object
   * 
   */
  ~Edge() {
    this->node_from_ = nullptr;
    this->node_to_ = nullptr;
  };

  /**
   * @brief Get the weight from node to node
   * 
   * @return int 
   */
  int Weight() {
    return this->weight_;
  };

  /**
   * @brief Get the node from
   * 
   * @return Node* 
   */
  Node *NodeFrom() {
    return this->node_from_;
  };

  /**
   * @brief Get the node to
   * 
   * @return Node* 
   */
  Node *NodeTo() {
    return this->node_to_;
  };

 private:
  int weight_;
  Node *node_from_;
  Node *node_to_;
};

#endif // EDGE_H_
