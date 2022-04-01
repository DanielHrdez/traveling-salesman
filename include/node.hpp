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

#pragma once

class Node {
  private:
    Node* next = nullptr;
    int weight = 0;

  public:
    Node(Node* next, int weight);
    ~Node();
    Node* getNext();
    int getWeight();
};
