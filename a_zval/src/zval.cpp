/**
 * @file zval.cpp
 * Code to create Z-array and use Z-values for exact pattern matching.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "zval.h"

/**
 * Returns the number of character comparisons required to find the first mismatch
 * or to completely match strings X and Y.
 *
 * @param X A std::string object which holds the first string being matched
 * @param Y An std::string object which holds the second string being matched
 *
 * @return An std::pair<int, int>. 
 *         The first value is the number of individual character comparisons needed.
 *         The second value is the longest common prefix length (match length)
 */

 std::pair<int,int> lr_scan(std::string X, std::string Y){
  int charComps = 0;

  // The std::pair object is defined with two variable types (in this case both int)
  std::pair<int, int> out;

  std::string lcp = "";
  unsigned min_length = std::min(X.length(), Y.length());
  unsigned count = 0;
  while (count < min_length) {
    charComps++;
    if (X[count] == Y[count]) {
      lcp = lcp + X[count];
      count++;
    }
    else {
      break;
    }
  }
  out.first = charComps;
  out.second = lcp.length();

  return out;
 }


/**
 * Returns an array which stores the Z-value at each position i<0
 * The 0th position (i=0) should store the total number of 
 * Also modifies the input (empty) zArray to store the Z-value at each position i<0
 *
 * @param S A std::string object which holds the String being analyzed.
 * @param Z An int* that points to a length |S| int[] which holds the zArray.
 *
 * @return An integer counting the number of character comparisons needed to make the Z-array.
 */
int create_zarray(std::string S, int* Z) {
  int charComps = 0; //the number of character comparisons needed to make the Z-array
  Z[0] = 0;
  std::pair<int,int> scan;
  for (unsigned long i = 1; i < S.length(); i++) {
    scan = lr_scan(S.substr(i,S.length() - i),S);
    Z[i] = scan.second;
    charComps += scan.first;
  }

  return charComps;
}


/**
 * Returns the index positions of all exact matches of P in T.
 * If no match is found, returns a vector with one value '[-1]'
 * NOTE: We want the exact matches *in T* not string S.
 *
 * Search the Text string (T) for the Pattern string (P)
 * For example, if P = 'AAA' and T = 'BAAAT', will return 1
 *
 * @param P A std::string object which holds the Pattern string.
 * @param T A std::string object which holds the Text string.
 *
 * @return An std::vector<int> array containing ALL index matches.
 */
std::vector<int> zval_search(std::string P, std::string T) {
  std::vector<int> outList;
  
  // NOTE: You should change this function as necessary to complete the assignment.
  std::string S = P + '$' + T;
  
  int *zarr = new int[S.length()];

  int charComps = create_zarray(S, zarr);

  // NOTE: You may not have seen std::vector<int> before. It is a dynamic array, useful for 
  //       situations where you don't know how large to make your array allocation. 

  int length = P.length();
  for (unsigned long i = 0; i < S.length(); i++) {
    if (zarr[i + length + 1] == length) {
      outList.push_back(i);
    }
  }

  // The vector can check if it is currently empty
  if (outList.empty()) { // bool empty() const; returns if my dynamic array is empty.
    std::cout << "ERROR: I'm not supposed to output an empty list!" << std::endl;
    // outList.push_back( <value> ) will append (or add) a value to the end of a dynamic array
    // What value are you supposed to return if you find no matches?
    outList.push_back(-1);
  }

  delete[] zarr; // No memory leaks here!

  return outList;
}