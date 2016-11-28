#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>

#include "Base.hpp"
#include "Solution.hpp"
#include <algorithm>
#include <list>
#include <utility>


/*struct Solutions_comparator {
	bool operator() (const std::set<Base>& left, const std::set<Base>& right) {

	}
};*/

struct Neighbourhood_generator
{
	Solution & actual;
	std::list<std::set<Base>> generated;

	Neighbourhood_generator(Solution & actual);
	bool is_new(Solution & candidate); //checks if new generated solution is unique -wasn't used before
	Solution next();
	bool comparator(std::set<Base>& a, std::set<Base>& b) {
		
	}
};

