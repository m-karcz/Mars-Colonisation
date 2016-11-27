#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include "Solution.hpp"
#include "Base.hpp"

struct Neighbourhood_generator
{
	Solution & actual;
	std::set<std::vector<Base>> generated;

	Neighbourhood_generator(Solution & actual);
	Solution next();
};