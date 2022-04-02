/**
 * @file read_graph.h
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Read Graph class to represent a Graph object
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef READ_GRAPH_H_
#define READ_GRAPH_H_

#include <fstream>

#include "../graph/graph.h"

class ReadGraph {
 public:
  /**
   * @brief Read the graph from file
   * 
   * @return Graph
   */
  Graph Read(char const*file_name);

  /**
   * @brief Calculate the number of edges of the graph
   * 
   * @param number_of_nodes Number of nodes of the graph
   * @return int 
   */
  int NumberOfEdges(int number_of_nodes) {
    if (number_of_nodes <= 1) return 0;
    const int kNodesMinusOne = number_of_nodes - 1;
    return kNodesMinusOne + NumberOfEdges(kNodesMinusOne);
  };

  int NodeIn(char node_name, std::vector<Node *> nodes) {
    for (int i = 0; i < nodes.size(); i++) {
      if (nodes[i]->name == node_name) return i;
    }
    return -1;
  };
};

#endif // READ_GRAPH_H_
