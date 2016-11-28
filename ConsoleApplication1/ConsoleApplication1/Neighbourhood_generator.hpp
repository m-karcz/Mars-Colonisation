#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>

#include "Base.hpp"
#include "Solution.hpp"
#include <algorithm>


struct Neighbourhood_generator
{
	Solution & actual;
	std::set<std::vector<Base>> generated;

	Neighbourhood_generator(Solution & actual);
	bool is_new(Solution & candidate); //checks if new generated solution is unique -wasn't used before
	Solution next();
};