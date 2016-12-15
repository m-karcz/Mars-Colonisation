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
	int width;			//map width
	int height;			//map height
	
	bool simple_used;
	int prev_move;
	bool better;

	std::list<std::multiset<Base>> generated;
	Neighbourhood_generator(std::shared_ptr<Graph> map) : height(static_cast<int>(map->points.size())-1), width(static_cast<int>(map->points[0].size())-1), simple_used(false) {}
	bool is_new(std::shared_ptr<Solution> candidate); //checks if new generated solution is unique -wasn't used before
	bool is_inside(std::shared_ptr<Solution> candidate); //checks if the new genrated solution is inside the map
	std::shared_ptr<Solution> next(std::shared_ptr<Solution> actual);

	std::shared_ptr<Solution>  Neighbourhood_generator::generate_simple_neighbourhood(std::shared_ptr<Solution> actual);
	std::shared_ptr<Solution>  Neighbourhood_generator::generate_random_neighbourhood(std::shared_ptr<Solution> actual);

	bool comparator(std::multiset<Base>& a, std::multiset<Base>& b) {
		
	}
};

