/**
 * @file sarray.cpp
 * Code to using suffix arrays for exact pattern matching.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>

#include "sarray.h"


/**
 * Returns the suffix array of T as an int vector.
 *
 * @param T A std::string object which holds the text being pre-processed.
 *
 * @return An std::vector<int> storing the suffix array
 */
std::vector<int> build_sarray(std::string T){
  std::vector<int> sarray;

  //Your code here

  T = T + '$';
  std::vector<std::string> suffixes;
  for (size_t i = 0; i < T.size(); i++) {
    suffixes.push_back(T.substr(i,T.size() - i));
  }
  std::sort(suffixes.begin(), suffixes.end());
  for (size_t i = 0; i < suffixes.size(); i++) {
    sarray.push_back(T.size() - suffixes[i].size());
  }


  return sarray;
}


/**
 * Returns a vector of indices containing all exact pattern match locations
 *
 * @param P A std::string object which holds the pattern being searched
 * @param T A std::string object which holds the text the SA is built on [excluding '$']
 * @param sarray A std::vector<int> which holds the suffix array
 *
 * @return An std::vector<int> storing all matching index positions
 * NOTE: For full credit, you must use the suffix array
 */
std::vector<int> sarray_search(std::string P, std::string T, std::vector<int> sarray){
  std::vector<int> outList;

  // To avoid confusion, the input T will be the same for both functions.
  T = T+"$"; 

  // YOUR CODE HERE
  int smallest = getSmallest(P, T, sarray, 0, sarray.size() - 1);
  int largest = getLargest(P, T, sarray, 0, sarray.size() - 1);
  if (smallest == -1){
    outList.push_back(-1);
    return outList;
  }
  for (int i = smallest; i <= largest; i++) {
    outList.push_back(sarray[i]);
  }


  return outList; 
}


int getSmallest(std::string P, std::string T, std::vector<int> sarray, int l, int r){

  // YOUR CODE HERE (if you think it helpful)
  if (l > r) {
    return -1;
  }
  int smallest = -1;
  int middle = (l + r) / 2;
  int length = T.size() - sarray[middle];
  std::string str = T.substr(T.size() - length, length);
  if ((size_t) length >= P.size() && str.substr(0, P.size()) == P) {
    smallest = middle;
    int evenSmaller = getSmallest(P, T, sarray, l, middle - 1);
    if (evenSmaller != -1) {
      smallest = evenSmaller;
    }
  }
  else if (str < P) {
    smallest = getSmallest(P, T, sarray, middle + 1, r);
  }
  else {
    smallest = getSmallest(P, T, sarray, l, middle - 1);
  }
  return smallest;
}

int getLargest(std::string P, std::string T, std::vector<int> sarray, int l, int r){

  // YOUR CODE HERE (if you think it helpful)
  if (l > r) {
    return -1;
  }
  int largest = -1;
  int middle = (l + r) / 2;
  int length = T.size() - sarray[middle];
  std::string str = T.substr(T.size() - length, length);
  if ((size_t) length >= P.size() && str.substr(0, P.size()) == P) {
    largest = middle;
    int evenLarger = getLargest(P, T, sarray, middle + 1, r);
    if (evenLarger != -1) {
      largest = evenLarger;
    }
  }
  else if (str < P) {
    largest = getLargest(P, T, sarray, middle + 1, r);
  }
  else {
    largest = getLargest(P, T, sarray, l, middle - 1);
  }
  return largest;
}