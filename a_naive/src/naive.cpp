/**
 * @file naive.cpp
 * Intro to strings, pattern matching, and prefix/suffixes .
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

#include "naive.h"

/**
 * Returns the index position of the first exact match of P in T.
 * If no match is found, returns the value '-1'
 *
 * Search the Text string (T) for the Pattern string (P)
 * For example, if P = 'AAA' and T = 'BAAAT', will return 1
 *
 * @param P A std::string object which holds the Pattern string.
 * @param T A std::string object which holds the Text string.
 *
 * @return An integer.
 */
int naive_search(std::string P, std::string T) {
  
  // YOUR CODE HERE
  if (P.length() > T.length()) {
    return -1;
  }
  for (unsigned i = 0; i <= T.length() - P.length(); i++) {
    if (T.substr(i, P.length()) == P) {
      return i;
    }
  }

  return -1;
}

/**
 * Returns the string corresponding to the longest common prefix between P and T
 * If there is no common prefix, returns an empty string.
 *
 * @param P A std::string object which holds the Pattern string.
 * @param T A std::string object which holds the Text string.
 *
 * @return An std::string.
 */
std::string longest_common_prefix(std::string P, std::string T) {
  std::string lcp = "";

  // YOUR CODE HERE
  unsigned min_length = std::min(P.length(), T.length());
  unsigned count = 0;
  while (P[count] == T[count]) {
    lcp = lcp + P[count];
    count++;
    if (count >= min_length) {
      break;
    }
  }
  
  return lcp;
}

/**
 * Returns the string corresponding to the longest common suffix between P and T
 * If there is no common suffix, returns an empty string.
 *
 * @param P A std::string object which holds the Pattern string.
 * @param T A std::string object which holds the Text string.
 *
 * @return An std::string.
 */
std::string longest_common_suffix(std::string P, std::string T) {
  std::string lcs = "";
  if (P.length() == 0 || T.length() == 0) {
    return "";
  }
  
  unsigned min_length = std::min(P.length(), T.length());
  unsigned count = 0;
  while (T[T.length() - 1 - count] == P[P.length() - 1 - count]) {
    lcs = P[P.length() - 1 - count] + lcs;
    count++;
    if (count >= min_length) {
      break;
    }
  }
  
  return lcs;
}


