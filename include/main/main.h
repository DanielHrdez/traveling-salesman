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

#include "../graph/graph.h"
#include "../io/read_graph.h"
#include "../tsp/tsp_brute_force.h"
#include "../tsp/tsp_greedy.h"
#include "../tsp/tsp_dynamic.h"

#include "constants.h"

#include <iostream>
#include <chrono>
#include <Windows.h>
#include <tuple>

using AlgorithmSolutions = std::vector<std::tuple<int, std::tuple<int, int, int>, std::vector<std::chrono::duration<double>>>>;

void PrintTitle();
std::vector<Graph> GenerateGraphs(int number_of_graphs);
AlgorithmSolutions ExecuteAlgorithms(std::vector<Graph> graphs);
void PrintTable(AlgorithmSolutions solutions);
