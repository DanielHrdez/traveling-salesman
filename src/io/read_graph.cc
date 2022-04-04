/**
 * @file read_graph.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/io/read_graph.h"

Graph ReadGraph::Read(char const*file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) throw std::runtime_error("Error opening file");
  
  int number_of_nodes;
  int number_of_edges;
  file >> number_of_nodes;
  number_of_edges = this->NumberOfEdges(number_of_nodes);
  std::vector<Edge> edges;
  std::vector<Node *> nodes(number_of_nodes);
  for (int i = 0; i < number_of_nodes; i++) {
    nodes[i] = new Node {(char)('A' + i), false};
  }
  Node *from;
  Node *to;
  int weight;
  char node_from;
  char node_to;
  int node_pos = 0;
  int pos_from;
  int pos_to;

  for (int i = 0; i < number_of_edges; i++) {
    file >> node_from >> node_to >> weight;
    pos_from = this->NodeIn(node_from, nodes);
    if (pos_from == -1) {
      nodes[node_pos]->Id(node_from);
      from = nodes[node_pos];
      node_pos++;
    } else {
      from = nodes[pos_from];
    }
    pos_to = this->NodeIn(node_to, nodes);
    if (pos_to == -1) {
      nodes[node_pos]->Id(node_to);
      to = nodes[node_pos];
      node_pos++;
    } else {
      to = nodes[pos_to];
    }
    edges.push_back(Edge(from, to, weight));
  }

  file.close();
  return Graph(edges, nodes);
};
