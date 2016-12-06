#pragma once
#include <vector>
#include <set>
#include "Base.hpp"
#include <memory>
struct Graph;
struct Base;

struct Solution {
	long achievable_points = 0;
	std::multiset<Base> bases;
	void objective_function(std::shared_ptr<Graph> map, const long range);
	void move(Base& base,const unsigned int where_to_move);
	Solution(const Solution & pattern); 
	static std::shared_ptr<Solution> generate_initial(int x, int y, int amount)
	{
		auto solution = std::make_shared<Solution>();
		for (;amount > 0; amount--) {
			solution->bases.emplace(x++, y);
		}
		return solution;
	}
	Solution(){}
private:
};
