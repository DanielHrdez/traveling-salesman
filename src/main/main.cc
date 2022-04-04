/**
 * @file main.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief Main program to execute the TSP algorithms
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/main/main.h"

int main() {
  PrintTitle();
  std::vector<Graph> graphs = GenerateGraphs(10);
  AlgorithmSolutions solutions = ExecuteAlgorithms(graphs);
  PrintTable(solutions);
}

void PrintTable(AlgorithmSolutions solutions) {
  const char *bar = "| Instance | Brute Force | Time (ms) | Dynamic | Time (ms) | Greedy | Time (ms) |";
  std::cout << bar << std::endl;
  for (auto solution : solutions) {
    int number_of_nodes = std::get<0>(solution);
    std::tuple<int, int, int> solutions = std::get<1>(solution);
    std::vector<std::chrono::duration<double>> time_result = std::get<2>(solution);

    std::cout << "| " << number_of_nodes << "_nodos.txt ";
    std::cout << "| " << std::get<0>(solutions) << " ";
    std::cout << "| " << time_result[0].count() << " ";
    std::cout << "| " << std::get<1>(solutions) << " ";
    std::cout << "| " << time_result[1].count() << " ";
    std::cout << "| " << std::get<2>(solutions) << " ";
    std::cout << "| " << time_result[2].count() << " |" << std::endl;
  }
}

AlgorithmSolutions ExecuteAlgorithms(std::vector<Graph> graphs) {
  AlgorithmSolutions solutions;
  std::vector<std::chrono::duration<double>> time_results;

  for (Graph graph : graphs) {
    std::chrono::time_point<std::chrono::system_clock> start, end;

    TspBruteForce brute_force(graph);
    start = std::chrono::system_clock::now();
    std::pair<std::vector<Node *>, int> brute_force_solution = brute_force.Solve();
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    time_results.push_back(elapsed_seconds);

    TspDynamic dynamic(graph);
    start = std::chrono::system_clock::now();
    std::pair<std::vector<Node *>, int> dynamic_solution = dynamic.Solve();
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    time_results.push_back(elapsed_seconds);

    TspGreedy greedy(graph);
    start = std::chrono::system_clock::now();
    std::pair<std::vector<Node *>, int> greedy_solution = greedy.Solve();
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    time_results.push_back(elapsed_seconds);

    solutions.push_back({
      (int) graph.Nodes().size(),
      {
        brute_force_solution.second,
        dynamic_solution.second,
        greedy_solution.second
      },
      time_results
    });
  }

  return solutions;
}

void PrintTitle() {
  SetConsoleOutputCP(CP_UTF8);
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, 11);
  std::cout << kTitle << std::endl;
  SetConsoleTextAttribute(hConsole, 15);
}

std::vector<Graph> GenerateGraphs(int number_of_graphs) {
  std::vector<Graph> graphs;
  std::vector<Node *> nodes;
  std::vector<Edge> edges;

  for (int i = 1; i <= number_of_graphs; i++) {
    for (int j = 0; j < i; j++) {
      nodes.push_back(new Node((char)j));
    }
    for (int j = 0; j < i; j++) {
      for (int k = j + 1; k < i; k++) {
        edges.push_back(Edge(nodes[j], nodes[k], rand() % 100));
      }
    }
    graphs.push_back(Graph(edges, nodes));
  }

  return graphs;
}
