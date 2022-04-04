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
  Node(char id = '\0', bool visited = false)
      : id_(id), visited_(visited) {}
  
  ~Node() {}

  char Id() const {
    return id_;
  }

  bool Visited() const {
    return visited_;
  }

  void Id(char id) {
    id_ = id;
  }

  void Visited(bool visited) {
    visited_ = visited;
  }

  inline bool operator==(const Node &node) const {
    return id_ == node.id_;
  }

  inline bool operator!=(const Node &node) const {
    return id_ != node.id_;
  }

  inline friend std::ostream &operator<<(std::ostream &os, const Node &node) {
    os << node.id_;
    return os;
  }

 private:
  char id_;
  bool visited_;
};

#endif // NODE_H_
