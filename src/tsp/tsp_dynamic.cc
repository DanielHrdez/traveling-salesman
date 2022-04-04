/**
 * @file tsp_dynamic.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief TSP in dynamic programming
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../../include/tsp/tsp_dynamic.h"
#include <unordered_map>
#include <algorithm>
#include <set>

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2;
  }
};

std::pair<std::vector<Node *>, int> TspDynamic::Solve() {
  return std::pair<std::vector<Node *>, int>(
    std::vector<Node *>(),
    0
  );
}
