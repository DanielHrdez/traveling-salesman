/**
 * @file read_graph.test.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Test for Read Graph class
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/io/read_graph.h"
#include "../tester.h"

void BadInputFile() {
  std::cout << "Bad input file" << std::endl;
  ReadGraph read_graph;
  try {
    read_graph.Read("bad_file.txt");
  } catch (std::runtime_error &e) {
    EXPECT_EQ("Error opening file", e.what());
  }
}

void NumberOfEdges() {
  std::cout << "Number of edges" << std::endl;
  ReadGraph read_graph;
  EXPECT_EQ(read_graph.NumberOfEdges(-1), 0);
  EXPECT_EQ(read_graph.NumberOfEdges(1), 0);
  EXPECT_EQ(read_graph.NumberOfEdges(2), 1);
  EXPECT_EQ(read_graph.NumberOfEdges(3), 3);
  EXPECT_EQ(read_graph.NumberOfEdges(4), 6);
  EXPECT_EQ(read_graph.NumberOfEdges(5), 10);
}

void NodeIn() {
  std::cout << "Node in" << std::endl;
  ReadGraph read_graph;
  std::vector<Node *> nodes = {
    new Node {'A', false},
    new Node {'B', false},
    new Node {'C', false},
    new Node {'D', false},
    new Node {'E', false}
  };
  EXPECT_EQ(read_graph.NodeIn('A', nodes), 0);
  EXPECT_EQ(read_graph.NodeIn('B', nodes), 1);
  EXPECT_EQ(read_graph.NodeIn('C', nodes), 2);
  EXPECT_EQ(read_graph.NodeIn('D', nodes), 3);
  EXPECT_EQ(read_graph.NodeIn('E', nodes), 4);
  EXPECT_EQ(read_graph.NodeIn('F', nodes), -1);
}

void Read() {
  std::cout << "Read graph_1.txt" << std::endl;
  ReadGraph read_graph;
  Graph graph = read_graph.Read("C:\\Users\\Danie\\Desktop\\traveling-salesman\\data\\graph_1.txt");
  EXPECT_EQ(graph.NumberOfEdges(), 6);
  EXPECT_EQ(graph.NumberOfNodes(), 4);
  EXPECT_EQ(graph.Nodes()[0]->name, 'A');
  EXPECT_EQ(graph.Nodes()[1]->name, 'B');
  EXPECT_EQ(graph.Nodes()[2]->name, 'C');
  EXPECT_EQ(graph.Nodes()[3]->name, 'D');
  EXPECT_EQ(graph.Edges()[0].NodeFrom()->name, 'A');
  EXPECT_EQ(graph.Edges()[0].NodeTo()->name, 'B');
  EXPECT_EQ(graph.Edges()[0].Weight(), 25);
  EXPECT_EQ(graph.Edges()[1].NodeFrom()->name, 'A');
  EXPECT_EQ(graph.Edges()[1].NodeTo()->name, 'C');
  EXPECT_EQ(graph.Edges()[1].Weight(), 10);
  EXPECT_EQ(graph.Edges()[2].NodeFrom()->name, 'A');
  EXPECT_EQ(graph.Edges()[2].NodeTo()->name, 'D');
  EXPECT_EQ(graph.Edges()[2].Weight(), 15);
  EXPECT_EQ(graph.Edges()[3].NodeFrom()->name, 'B');
  EXPECT_EQ(graph.Edges()[3].NodeTo()->name, 'C');
  EXPECT_EQ(graph.Edges()[3].Weight(), 10);
  EXPECT_EQ(graph.Edges()[4].NodeFrom()->name, 'B');
  EXPECT_EQ(graph.Edges()[4].NodeTo()->name, 'D');
  EXPECT_EQ(graph.Edges()[4].Weight(), 45);
  EXPECT_EQ(graph.Edges()[5].NodeFrom()->name, 'C');
  EXPECT_EQ(graph.Edges()[5].NodeTo()->name, 'D');
  EXPECT_EQ(graph.Edges()[5].Weight(), 5);
}

int main() {
  BadInputFile();
  NumberOfEdges();
  NodeIn();
  Read();
}
