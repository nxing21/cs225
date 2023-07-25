/**
 * @file bmoore.cpp
 * Code to Boyer-Moore solution for exact pattern matching.
 * Uses strong bad character rule only
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>

#include "bmoore.h"

/**
 * Takes in two strings (P and the alphabet) 
 * Returns a 2D array containing the skip values for bad character rule
 *
 * @param P A std::string object which holds the pattern being pre-processed.
 * @param alpha An std::string object which holds all characters in the alphabet of P and T.
 *
 * @return An std::vector<std::vector<int>> (a 2D array of integers) storing the bad character array
 * BC_array rows correspond to the alphabet and the columns correspond to positions along the pattern.
 */
std::vector<std::vector<int>> prep_bc_array(std::string P, std::string alpha){

  // This character lookup dictionary *might* be useful to your preprocessing.
  // You don't have to use it.
  std::map<char, int> charLookup;

  // This 2D array will be necessary to your solution.
  // Remember that <vname>.push_back(i) will add i to the end of <vname>.
  // Further tip: This is a vector of (vectors of integers).
  std::vector<std::vector<int>> bc_array;

    // This is just an example on how to build a 2D array
    // You should replace it with whatever code you need
    std::vector<int> rows;
    for (size_t i = 0; i < P.size(); i++) {
      rows.push_back(-1);
    }
    for (size_t i = 0; i < alpha.size(); i++) {
      bc_array.push_back(rows);
    }

    for (size_t i = 0; i < bc_array.size(); i++) {
      for (size_t j = 0; j < bc_array[0].size(); j++) {
        int count = j - 1;
        int numSkips = 0;
        while (count >= 0) {
          if (P[count] != alpha[i]) {
            numSkips++;
            count--;
          }
          else {
            break;
          }
        }
        bc_array[i][j] = numSkips;
      }
    }

  return bc_array;

}

/**
 * Returns the index positions of first instance of c in alpha.
 * If no match is found, returns the value '-1'
 *
 * A potentually useful helper function for relating characters to integers
 * As a fun fact, this was a valid solution to naive_search (Week 1)
 *
 * NOTE: This is not actually an efficient solution but we are handwaving it here.
 *
 * @param alpha A std::string object which holds the alphabet string.
 * @param c A char object which holds the character being searched for
 *
 * @return An integer containing the index position of c in alpha
 */
int findChar(std::string alpha, char c){
  return alpha.find(c);
}

/**
 * Returns the number of alignments skipped by Boyer-Moore
 * In this instance, Boyer-Moore is *only* the strong bad character rule [and right-to-left scanning]
 *
 * Also modifies the outlist vector to contain the index positions of all exact matches of P in T.
 * If no match is found, modifies the vector to contain one value '[-1]'
 *
 * @param P A std::string object which holds the Pattern string.
 * @param T A std::string object which holds the Text string.
 * @param alpha A std::string object which holds the Alphabet string.
 * @param outList An std::vector<int> array (by reference) that can be modified to contain all matches
 *
 * @return An int counting the number of skipped alignments using bad character.
 */
int bmoore_search(std::string P, std::string T, std::string alpha, std::vector<int> & outList){
  int skip = 0;

  // Pre-compute BC array
  // Your solution must use this array.
  std::vector<std::vector<int>> bc_array = prep_bc_array(P, alpha);

  int i = 0;

  bool match;
  while ((size_t) i < T.size() - P.size() + 1) {
    match = true;
    for (size_t j = 0; j < P.size(); j++) {
      if (P[P.size() - 1 - j] != T[i + P.size() - 1 - j]) {
        int numSkips = bc_array[findChar(alpha,T[i + P.size() - 1 - j])][P.size() - 1 - j];
        if ((size_t) i + numSkips >= T.size() - P.size()) {
          numSkips = T.size() - P.size() - i;
        }
        skip += numSkips;
        i += numSkips;
        match = false;
        break;
      }
    }
    if (match) {
      outList.push_back(i);
    }
    i++;
  }

  if (outList.size() == 0) {
    outList.push_back(-1);
  }
  return skip;
}