#pragma once
#include <vector>
#include <set>
#include "Base.hpp"
struct Graph;
struct Base;

struct Solution {
	long achievable_points = 0;
	std::set<Base> bases;
	void objective_function(Graph & map, const int range);
	void move(const unsigned int base,const unsigned int where_to_move);
	Solution() {}
	//Solution(const Solution & pattern); //TODO
};