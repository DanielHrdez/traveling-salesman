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

#ifdef _WIN32
#include <Windows.h>
#endif

#include "../graph/random_graph.h"
#include "../io/read_graph.h"
#include "../io/write_graph.h"
#include "../tsp/tsp_brute_force.h"
#include "../tsp/tsp_greedy.h"
#include "../tsp/tsp_dynamic.h"

#include "text_table.h"
#include "constants.h"

#include <iostream>
#include <chrono>
#include <tuple>
#include <string>

using Solution = std::tuple<int, std::tuple<int, int, int>, std::vector<std::chrono::duration<double>>>;
using AlgorithmSolutions = std::vector<std::tuple<int, std::tuple<int, int, int>, std::vector<std::chrono::duration<double>>>>;

/**
 * @brief Check if the argmuents are correct
 * 
 * @param number_of_arguments Number of arguments
 * @param arguments Arguments
 * @return std::pair<char *, int> The result of the arguments
 */
std::pair<char *, int> CheckArguments(int number_of_arguments, char *arguments[]);

/**
 * @brief Print the title of the program
 * 
 */
void PrintTitle();

/**
 * @brief Generate a graph and store it in a file
 * 
 * @param number_of_nodes Number of nodes of the graph
 * @param directory Directory where the graph will be stored
 * @return Graph The generated graph
 */
Graph GenerateGraph(int number_of_nodes, char *directory);

/**
 * @brief Execute the algorithms and return the solutions
 * 
 * @param graph The graph to execute the algorithms
 * @param start_time The start time of the program
 * @return Solution The solutions of the algorithms
 */
Solution ExecuteAlgorithms(Graph graph, std::chrono::time_point<std::chrono::system_clock> start_time);

/**
 * @brief Print the results of the algorithms
 * 
 * @param solutions The solutions of the algorithms
 */
void PrintTable(AlgorithmSolutions solutions);

/**
 * @brief Execute the main loop of the program with the specific time limit
 * 
 * @return AlgorithmSolutions The solutions of the algorithms
 */
AlgorithmSolutions MainLoop(char *, int);
