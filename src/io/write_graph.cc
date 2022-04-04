/**
 * @file write_graph.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Write Graph class to represent a Graph object
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/io/write_graph.h"

void WriteGraph::Write(Graph graph, char const*file_name) {
  std::ofstream file;
  file.open(file_name);
  file << graph.NumberOfNodes() << std::endl;
  for (int i = 0; i < graph.NumberOfNodes(); i++) {
    for (int j = i + 1; j < graph.NumberOfNodes(); j++) {
      Node *node_i = graph.Nodes()[i];
      Node *node_j = graph.Nodes()[j];
      file << node_i->Id() << " " << node_j->Id() << " "
           << graph.Travel(node_i, node_j) << std::endl;
    }
  }
  file.close();
}
