#pragma once
struct Solution {
	long achievable_points = 0;
	std::vector<Base> bases;
	void objective_function(Graph & map);
};