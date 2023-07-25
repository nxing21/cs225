/**
 * @file bwt.cpp
 * Code to encoding and decoding a text using the BWT
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>

#include "bwt.h"

/**
 * Returns a vector of strings containing all rotations of a text
 *
 * @param T A std::string object which holds the text being pre-processed.
 *
 * @return An std::vector<std::string> storing all rotations
 */
std::vector<std::string> rotate(std::string T){

  // Your code here (if you think it will help)
  std::vector<std::string> out;

  for (size_t i = 0; i < T.size(); i++) {
    out.push_back(T);
    T = T + T.substr(0,1);
    T = T.substr(1,T.size() - 1);
  }

  return out;
}


/**
 * Returns the BWT of T as a string
 *
 * @param T A std::string object which holds the text being pre-processed.
 *
 * @return An std::string storing the BWT
 */
std::string encode_bwt(std::string T){

  // Your code here
  T = T + '$';
  std::string encode = "";
  std::vector<std::string> vec = rotate(T);
  std::sort(vec.begin(), vec.end());
  for (size_t i = 0; i < vec.size(); i++) {
    encode = encode + vec[i][T.size() - 1];
  }

  return encode;

}

/**
 * Returns the BWT of T as a string
 *
 * @param T A std::string object which holds the text being pre-processed.
 *
 * @return An std::string storing the BWT
 */

std::string decode_bwt(std::string bwt){

  // YOUR CODE HERE
  std::vector<std::string> vec;
  for (size_t i = 0; i < bwt.size(); i++) {
    vec.push_back("");
  }
  for (size_t k = 0; k < bwt.size(); k++) {
    for (size_t i = 0; i < bwt.size(); i++) {
      vec[i] = bwt[i] + vec[i];
    }
    std::sort(vec.begin(), vec.end());
  }
  std::string str;
  for (size_t i = 0; i < vec.size(); i++) {
    if (vec[i][vec[i].size() - 1] == '$') {
      str = vec[i];
      break;
    }
  }
  return str.substr(0,str.size() - 1);
}
