/**
 * @file edist.cpp
 * Code to build an edit distance matrix
 * and return an optimal edit string
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>

#include "edist.h"

/**
 * Returns an edit distance matrix between strings X and Y [Dimensions (|X|+1) x |Y|+1)]
 *
 * @param X A std::string object holding the X string (edits with respect to X)
 * @param Y A std::string object holding the Y string (edits turn X into Y)
 *
 * @return An std::vector<std::vector<int>> (typedef eMatrix) storing the optimal edit
 *         distance between a length i substring of X and a length j substring of Y
 *         at position eMatrix[i][j].
 */
eMatrix buildEditMatrix(std::string x, std::string y){
  eMatrix outM;

  // YOUR CODE HERE

  // Some loose guidelines:

  // Dont forget that the first row / column are gaps
  // (You may need to adjust index or add a gap character)

  // Build an empty matrix of appropriate size

  // What entries can you calculate immediately?

  // Write a dynamic program to fill in the rest


  return outM;
}

/**
 * Returns the edit string between strings X and Y
 *
 * @param X A std::string object holding the X string (edits with respect to X)
 * @param Y A std::string object holding the Y string (edits turn X into Y)
 *
 * @return An std::string storing an optimal edit string
 *
 * WARNING: There are often multiple possible optimal strings. You MUST use the provided 
 *          'greedy' logic to produce the same optimal string as the autograder.
 *
 *          That is to say, you must prioritize M/R, followed by D, followed by I when
 *          there are multiple possible edit strings. (Remember you build backwards)
 */
std::string buildEditString(std::string x, std::string y){
  eMatrix myM = buildEditMatrix(x,y);
  std::string es = "";

  // your code here


  return es;
}