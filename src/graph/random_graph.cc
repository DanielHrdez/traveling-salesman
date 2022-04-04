/**
 * @file random_graph.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Random Graph class to represent a Graph object
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/graph/random_graph.h"

Graph RandomGraph::Generate(int number_of_nodes) {
  std::vector<Node *> nodes;
  std::vector<Edge> edges;
  for (int i = 0; i < number_of_nodes; i++) {
    nodes.push_back(new Node(i));
  }
  for (int i = 0; i < number_of_nodes; i++) {
    for (int j = i + 1; j < number_of_nodes; j++) {
      int weight = rand() % 100;
      edges.push_back(Edge(nodes[i], nodes[j], weight));
    }
  }
  return Graph(edges, nodes);
}
