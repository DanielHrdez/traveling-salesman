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

int main(int argc, char *argv[]) {
  std::pair<char *, int> argument_pair = CheckArguments(argc, argv);
  char * directory = argument_pair.first;
  int time_limit = argument_pair.second;
  PrintTitle();
  std::vector<Graph> graphs = GenerateGraphs(DEFAULT_NUMBER_GRAPHS, directory);
  // AlgorithmSolutions solutions = ExecuteAlgorithms(graphs, time_limit);
  // PrintTable(solutions);
}

std::pair<char *, int> CheckArguments(int number_of_arguments, char *arguments[]) {
  if (number_of_arguments < 2) {
    std::cout << "Error: Invalid number of arguments" << std::endl;
    std::cout << "Usage: tsp <directory>" << std::endl;
    std::cout << "Optional: -t <time limit in seconds>" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::pair<char *, int> arguments_pair;
  arguments_pair.first = arguments[1];
  if (number_of_arguments == 4) {
    arguments_pair.second = (int) arguments[3];
  } else {
    arguments_pair.second = DEFAULT_TIME_LIMIT;
  }
  return arguments_pair;
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

AlgorithmSolutions ExecuteAlgorithms(std::vector<Graph> graphs, int time_limit) {
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
  std::cout << TITLE << std::endl;
  SetConsoleTextAttribute(hConsole, 15);
}

std::vector<Graph> GenerateGraphs(int number_of_graphs, char *directory) {
  std::vector<Graph> graphs;
  std::vector<Node *> nodes;
  std::vector<Edge> edges;
  RandomGraph generator;
  WriteGraph writer;

  for (int i = 1; i < number_of_graphs; i++) {
    graphs.push_back(generator.Generate(i + 1));
    writer.Write(graphs.back(), (char *) i);
  }

  return graphs;
}
