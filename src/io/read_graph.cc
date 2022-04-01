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

ReadGraph::ReadGraph(char *filename) {
  std::ifstream file(filename);
  if (!file.is_open()) throw std::runtime_error("Error opening file");
  int number_of_nodes;
  int number_of_edges;
  file >> number_of_nodes;
  number_of_edges = this->NumberOfEdges(number_of_nodes);
  Edge **edges = new Edge*[number_of_edges];
  Node *from;
  Node *to;
  int weight;
  for (int i = 0; i < number_of_edges; i++) {
    from = new Node;
    to = new Node;
    file >> from->name;
    file >> to->name;
    file >> weight;
    edges[i] = new Edge(from, to, weight);
  }
  file.close();
};