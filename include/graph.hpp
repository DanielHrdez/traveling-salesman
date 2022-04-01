/**
 * @file graph.hpp
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Graph class to represent a graph object
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include "node.hpp"

/**
 * @brief Enum for the types of a graph
 * 
 */
enum class GraphType {
  UNDIRECTED,
  DIRECTED,
};

/**
 * @brief Graph class to represent a graph object
 * 
 */
class Graph {
  private:
    GraphType type;
    Node nodes[];
};
