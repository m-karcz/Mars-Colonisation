#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>

#include "Base.hpp"
#include "Solution.hpp"


struct Neighbourhood_generator
{
	Solution & actual;
	std::set<std::vector<Base>> generated;

	Neighbourhood_generator(Solution & actual);
	Solution next();
};