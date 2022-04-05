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
  char *directory = argument_pair.first;
  int time_limit = argument_pair.second;
  PrintTitle();
  AlgorithmSolutions solutions = MainLoop(directory, time_limit);
  PrintTable(solutions);
}

AlgorithmSolutions MainLoop(char * directory, int time_limit) {
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  int number_of_nodes = 2;
  AlgorithmSolutions solutions;

  while (std::chrono::system_clock::now() - start < std::chrono::seconds(time_limit)) {
    Graph graph = GenerateGraph(number_of_nodes, directory);
    solutions.push_back(ExecuteAlgorithms(graph, start));
    number_of_nodes++;
  }

  std::cout << "\033[2K\rTerminated ✔" << std::endl;
  return solutions;
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
    arguments_pair.second = atoi(arguments[3]);
  } else {
    arguments_pair.second = DEFAULT_TIME_LIMIT;
  }
  return arguments_pair;
}

void PrintTable(AlgorithmSolutions solutions) {
  TextTable table;
  table.add("Instance");
  table.add("Brute Force");
  table.add("Time (ms)");
  table.add("Dynamic");
  table.add("Time (ms)");
  table.add("Greedy");
  table.add("Time (ms)");
  table.endOfRow();
  for (auto solution : solutions) {
    int number_of_nodes = std::get<0>(solution);
    std::tuple<int, int, int> solutions = std::get<1>(solution);
    TupleChronos time_result = std::get<2>(solution);
    table.add(std::to_string(number_of_nodes) + "_nodos.txt");
    table.add(std::to_string(std::get<0>(solutions)));
    table.add(std::to_string(std::get<0>(time_result).count()));
    table.add(std::to_string(std::get<1>(solutions)));
    table.add(std::to_string(std::get<1>(time_result).count()));
    table.add(std::to_string(std::get<2>(solutions)));
    table.add(std::to_string(std::get<2>(time_result).count()));
    table.endOfRow();
  }
  table.setAlignment(2, TextTable::Alignment::RIGHT);
  std::cout << table;
}

AlgorithmSolution ExecuteBruteForce(Graph graph, std::chrono::time_point<std::chrono::system_clock> start_time) {
  TspBruteForce brute_force(graph);
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::chrono::duration<double> time_result;
  int time_passed;

  std::cout << "\rBrute force algorithm - " << graph.NumberOfNodes() << " nodes... " << std::flush;
  start = std::chrono::system_clock::now();
  std::pair<std::vector<Node *>, int> brute_force_solution = brute_force.Solve();
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  time_result = elapsed_seconds;
  time_passed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start_time).count();
  std::cout << "\t" << time_passed << " seconds" << std::flush;

  return {brute_force_solution.second, time_result};
}

AlgorithmSolution ExecuteDynamic(Graph graph, std::chrono::time_point<std::chrono::system_clock> start_time) {
  TspDynamic dynamic(graph);
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::chrono::duration<double> time_result;
  int time_passed;

  std::cout << "\rDynamic algorithm - " << graph.NumberOfNodes() << " nodes...    " << std::flush;
  start = std::chrono::system_clock::now();
  std::pair<std::vector<Node *>, int> dynamic_solution = dynamic.Solve();
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  time_result = elapsed_seconds;
  time_passed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start_time).count();
  std::cout << "\t" << time_passed << " seconds" << std::flush;

  return {dynamic_solution.second, time_result};
}

AlgorithmSolution ExecuteGreedy(Graph graph, std::chrono::time_point<std::chrono::system_clock> start_time) {
  TspGreedy greedy(graph);
  std::chrono::time_point<std::chrono::system_clock> start, end;
  std::chrono::duration<double> time_result;
  int time_passed;

  std::cout << "\rGreedy algorithm - " << graph.NumberOfNodes() << " nodes...     " << std::flush;
  start = std::chrono::system_clock::now();
  std::pair<std::vector<Node *>, int> greedy_solution = greedy.Solve();
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  time_result = elapsed_seconds;
  time_passed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start_time).count();
  std::cout << "\t" << time_passed << " seconds" << std::flush;

  return {greedy_solution.second, time_result};
}

Solution ExecuteAlgorithms(Graph graph, std::chrono::time_point<std::chrono::system_clock> start_time) {
  AlgorithmSolution brute_force_solution = ExecuteBruteForce(graph, start_time);
  AlgorithmSolution dynamic_solution = ExecuteDynamic(graph, start_time);
  AlgorithmSolution greedy_solution = ExecuteGreedy(graph, start_time);

  return {
    (int) graph.Nodes().size(),
    {
      brute_force_solution.first,
      dynamic_solution.first,
      greedy_solution.first
    },
    {
      brute_force_solution.second,
      dynamic_solution.second,
      greedy_solution.second
    }
  };
}

void PrintTitle() {
  #ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
  #endif
  std::cout << "\033[1;36m" << TITLE << "\033[0m" << std::endl;
}

Graph GenerateGraph(int number_of_nodes, char *directory) {
  RandomGraph generator;
  WriteGraph writer;

  Graph graph = generator.Generate(number_of_nodes);
  std::string filename = DEFAULT_FOLDER + std::to_string(number_of_nodes) + "_nodos.txt";
  writer.Write(graph, filename);

  return graph;
}
