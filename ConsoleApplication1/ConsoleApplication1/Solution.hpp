#pragma once
#include <vector>

struct Graph;
struct Base;

struct Solution {
	long achievable_points = 0;
	std::vector<Base> bases;
	void objective_function(Graph & map, unsigned int range);
};