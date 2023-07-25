/**
 * @file bmoore.h
 * Declarations of Boyer-Moore pattern matching functions.
 */

#pragma once

#include <string>
#include <vector>
#include <map>

int findChar(std::string alpha, char c);
std::vector<std::vector<int>> prep_bc_array(std::string P, std::string alphabet);
int bmoore_search(std::string P, std::string T, std::string alpha, std::vector<int> & outList);