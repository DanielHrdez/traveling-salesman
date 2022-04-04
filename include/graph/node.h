/**
 * @file node.hpp
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Node class to represent a node object
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NODE_H_
#define NODE_H_

#include <ostream>

/**
 * @brief Node class for check if visited
 * 
 */
class Node {
 public:
  /**
   * @brief Construct a new Node object
   * 
   * @param id Id of the node
   * @param visited If the node is visited
   */
  Node(char id = '\0', bool visited = false)
      : id_(id), visited_(visited) {}
  
  /**
   * @brief Destroy the Node object
   * 
   */
  ~Node() {}

  /**
   * @brief Return the id of the node
   * 
   * @return char Id of the node
   */
  char Id() const {
    return id_;
  }

  /**
   * @brief Return if the node is visited
   * 
   * @return bool If the node is visited
   */
  bool Visited() const {
    return visited_;
  }

  /**
   * @brief Set the id of the node
   * 
   * @param id Id of the node
   */
  void Id(char id) {
    id_ = id;
  }

  /**
   * @brief Set if the node is visited
   * 
   * @param visited If the node is visited
   */
  void Visited(bool visited) {
    visited_ = visited;
  }

  /**
   * @brief Overload the operator << to print the node
   * 
   * @param os Output stream
   * @param node Node to print
   * @return std::ostream& Output stream
   */
  inline bool operator==(const Node &node) const {
    return id_ == node.id_;
  }

  /**
   * @brief Overload the operator << to print the node
   * 
   * @param os Output stream
   * @param node Node to print
   * @return std::ostream& Output stream
   */
  inline bool operator!=(const Node &node) const {
    return id_ != node.id_;
  }

  /**
   * @brief Overload the operator << to print the node
   * 
   * @param os Output stream
   * @param node Node to print
   * @return std::ostream& Output stream
   */
  inline friend std::ostream &operator<<(std::ostream &os, const Node &node) {
    os << node.id_;
    return os;
  }

 private:
  char id_;
  bool visited_;
};

#endif // NODE_H_
