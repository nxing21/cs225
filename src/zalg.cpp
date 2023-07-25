/**
 * @file zalg.cpp
 * Code to create Z-array and use Z-algorithm for exact pattern matching.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "zalg.h"
std::pair<int,int> lr_scan(std::string X, std::string Y)
{
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
 * Returns the number of individual character comparisons used by the Z-algorithm
 * Also modifies the input (empty) zArray to store the Z-value at each position i>0
 *
 * @param S A std::string object which holds the String being analyzed.
 * @param Z An int* that points to a length |S| int[] which holds the zArray.
 *
 * @return An integer counting the number of character comparisons needed to make the Z-array.
 */
int create_zarray(std::string S, int* Z) {
  // You need to track character comparisons. Here are two suggested ways: 
  int charComps = 0; //Count Directly! (Same as z-value assignment)
  cs225::zstring inS(S); //Use 'cs225::zstring' to automatically track comparisons
  Z[0] = 0;
  std::pair<int, int> scan;
  int beta;
  int k;
  while ((size_t) inS.i < S.length()) {
    if (inS.i > inS.r) {
      scan = lr_scan(S.substr(inS.i,S.length() - inS.i + 1),S);
      Z[inS.i] = scan.second;
      charComps += scan.first;
      if (Z[inS.i] != 0) {
        inS.l = inS.i;
        inS.r = inS.i + Z[inS.i] - 1;
      }
    }
    else {
      beta = inS.r - inS.i + 1;
      k = inS.i - inS.l;
      int zk = Z[k];
      if (Z[k] < beta) {
        Z[inS.i] = zk;
      }
      else if (Z[k] == beta) {
        scan = lr_scan(S.substr(zk,S.length() - zk + 1), S.substr(inS.i + zk, S.length() - inS.i - zk + 1));
        Z[inS.i] = zk + scan.second;
        charComps += scan.first;
        if (Z[inS.i] != 0) {
          inS.l = inS.i;
          inS.r = inS.i + Z[inS.i] - 1;
        }
      }
      else {
        Z[inS.i] = beta;
      }
    }
    inS.i++;
  }
  
  return charComps;
  return inS.getCharComps();
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
std::vector<int> zalg_search(std::string P, std::string T) {
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