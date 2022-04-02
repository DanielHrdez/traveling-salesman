/**
 * @file tester.cc
 * @author Daniel Hernandez de Leon (alu0101331720@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string.h>

template <typename T>
void EXPECT_EQ(T expected, T actual) {
  std::cout << "  expected: " << expected << "  actual: " << actual;
  if (expected == actual) {
    std::cout << "\033[1;32m - Test OK\033[0m" << std::endl;
  } else {
    std::cout << "\033[1;31m - Test FAILED\033[0m" << std::endl;
  }
}

void EXPECT_EQ(const char *expected, const char *actual) {
  std::cout << "  expected: " << expected << "  actual: " << actual;
  if (strcmp(expected, actual) == 0) {
    std::cout << "\033[1;32m - Test OK\033[0m" << std::endl;
  } else {
    std::cout << "\033[1;31m - Test FAILED\033[0m" << std::endl;
  }
}
