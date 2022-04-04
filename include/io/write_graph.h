/**
 * @file write_graph.h
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Write Graph class to represent a Graph object
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef WRITE_GRAPH_H_
#define WRITE_GRAPH_H_

#include <fstream>
#include <string>

#include "../graph/graph.h"

class WriteGraph {
 public:
  /**
   * @brief Read the graph from file
   * 
   * @return Graph
   */
  void Write(Graph graph, std::string file_name);
};

#endif // WRITE_GRAPH_H_
