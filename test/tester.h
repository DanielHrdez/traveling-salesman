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

#pragma once

#include <iostream>
#include <vector>
#include <string.h>

void EXPECT_TRUE(bool condition) {
  if (condition) {
    std::cout << "\033[1;32m - Test OK\033[0m" << std::endl;
    return;
  }
  std::cout << "\033[1;31m - Test FAILED\033[0m" << std::endl;
}

template <typename T>
void EXPECT_EQ(T actual, T expected) {
  std::cout << "  Expected: " << expected << "  Actual: " << actual;
  EXPECT_TRUE(expected == actual);
}

template <typename T, typename U>
void EXPECT_EQ(T actual, U expected) {
  std::cout << "  Expected: " << expected << "  Actual: " << actual;
  EXPECT_TRUE(expected == (T) actual);
}

void EXPECT_EQ(const char *actual, const char *expected) {
  std::cout << "  Expected: " << expected << "  Actual: " << actual;
  EXPECT_TRUE(strcmp(expected, actual) == 0);
}

template <typename T>
void EXPECT_DEEP_EQ(std::vector<T*> actual, std::vector<T*> expected) {
  if (expected.size() != actual.size()) {
    std::cout << "  Expected size: " << expected.size();
    std::cout << "  Actual size: " << actual.size();
    EXPECT_TRUE(false);
  }
  if (actual.size() == expected.size()) {
    for (int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(*actual[i], *expected[i]);
    }
  } else if (actual.size() > expected.size()) {
    for (int i = 0; i < expected.size(); i++) {
      EXPECT_EQ(*actual[i], *expected[i]);
    }
    for (int i = expected.size(); i < actual.size(); i++) {
      EXPECT_EQ(*actual[i], *expected[expected.size() - 1]);
    }
  } else {
    for (int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(*actual[i], *expected[i]);
    }
    for (int i = actual.size(); i < expected.size(); i++) {
      EXPECT_EQ(*actual[actual.size() - 1], *expected[i]);
    }
  }
}

template <typename T>
void EXPECT_DEEP_EQ(std::vector<T> actual, std::vector<T> expected) {
  if (expected.size() != actual.size()) {
    std::cout << "  Expected size: " << expected.size();
    std::cout << "  Actual size: " << actual.size();
    EXPECT_TRUE(false);
  }
  if (actual.size() == expected.size()) {
    for (int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(actual[i], expected[i]);
    }
  } else if (actual.size() > expected.size()) {
    for (int i = 0; i < expected.size(); i++) {
      EXPECT_EQ(actual[i], expected[i]);
    }
    for (int i = expected.size(); i < actual.size(); i++) {
      EXPECT_EQ(actual[i], expected[expected.size() - 1]);
    }
  } else {
    for (int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(actual[i], expected[i]);
    }
    for (int i = actual.size(); i < expected.size(); i++) {
      EXPECT_EQ(actual[actual.size() - 1], expected[i]);
    }
  }
}

template <typename T>
void EXPECT_DEEP_EQ(std::vector<std::vector<T>> actual, std::vector<std::vector<T>> expected) {
  if (expected.size() != actual.size()) {
    std::cout << "  Expected size: " << expected.size();
    std::cout << "  Actual size: " << actual.size();
    EXPECT_TRUE(false);
  }
  for (int i = 0; i < actual.size(); i++) {
    EXPECT_DEEP_EQ(actual[i], expected[i]);
  }
}
