#pragma once
#include <vector>
#include <set>
#include "Base.hpp"
struct Graph;
struct Base;

struct Solution {
	long achievable_points = 0;
	std::set<Base> bases;
	void objective_function(Graph & map, const long range);
	void move(const unsigned int base,const unsigned int where_to_move);
	Solution(const Solution & pattern); 
	static Solution generate_initial(int x, int y, int amount)
	{
		Solution solution;
		for (;amount > 0; amount--) {
			solution.bases.emplace(x, y);
		}
		return solution;
	}
private:
	Solution() {}
};
