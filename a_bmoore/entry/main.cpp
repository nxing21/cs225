/**
 * @file main.cpp
 * A simple C++ program for running Boyer-Moore search.
 */

#include <string>
#include <iostream>
#include <vector>
#include <map>

#include "bmoore.h"

int main() {


  std::cout << "example 1" << std::endl;

  std::string alpha = "ACGT";
  std::string P = "TCGC";
  std::string T = "TCGTTCGC";

  //P = "AAA";
  //T = "BBBB";

  std::vector<std::vector<int>> bc_array = prep_bc_array(P, alpha);

  // Print bc_array
  std::cout << "{ ";
  for (int i = 0; i < (int) bc_array.size(); ++i){
    std::cout << "{ ";
    for(int j = 0; j < (int) bc_array[i].size()-1; ++j){
      std::cout << bc_array[i][j] << ", ";
    }
    std::cout << bc_array[i][bc_array[i].size()-1] << "}, \\" << std::endl;
  }
  std::cout << "}" << std::endl;

  std::vector<int> outList;

  std::cout << "Char Skips: " << bmoore_search(P, T, alpha, outList) << std::endl;

  std::cout << "{ ";
    for (int val : outList){
      std::cout << val << ", ";
    }
  std::cout << "}" << std::endl;


  return 0;
}
