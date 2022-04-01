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

/**
 * @brief Node Struct for check if visited
 * 
 */
struct Node {
  char* name = "";
  bool visited = false;
};

#endif // NODE_H_
