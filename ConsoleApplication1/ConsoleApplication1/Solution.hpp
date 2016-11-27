#pragma once
#include <vector>
#include "Base.hpp"
#include "Graph.hpp"

struct Graph;

struct Solution {
	long achievable_points = 0;
	std::vector<Base> bases;
	void objective_function(Graph & map, unsigned int range);
};