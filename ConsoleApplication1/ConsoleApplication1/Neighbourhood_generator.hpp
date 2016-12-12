#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include <memory>

#include "Base.hpp"
#include "Solution.hpp"
#include "Graph.hpp"
#include <algorithm>
#include <list>
#include <utility>


/*struct Solutions_comparator {
	bool operator() (const std::set<Base>& left, const std::set<Base>& right) {

	}
};*/

struct Neighbourhood_generator
{
	int width;
	int height;
	std::list<std::multiset<Base>> generated;
	std::vector<Solution> candidates;
	Neighbourhood_generator(std::shared_ptr<Graph> map) : width(static_cast<int>(map->points.size())-1), height(static_cast<int>(map->points[0].size())-1) {}
	bool is_new(std::shared_ptr<Solution> candidate); //checks if new generated solution is unique -wasn't used before
	std::shared_ptr<Solution> next(std::shared_ptr<Solution> actual);
	bool comparator(std::multiset<Base>& a, std::multiset<Base>& b) {
		
	}
};

