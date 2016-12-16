#include "Solution.hpp"
#include "Graph.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <chrono>
#include "MainForm.h"
#include "Dijkstra.hpp"

using namespace std::chrono;



void Solution::move_bases(std::vector<Base> new_bases)
{
	bases = std::vector<Base>(new_bases.begin(), new_bases.end());
}

Solution::Solution(const Solution & pattern)
{
	bases = std::vector<Base>(pattern.bases.begin(), pattern.bases.end());
	achievable_points = pattern.achievable_points;
}

std::ostream & operator<< (std::ostream & output, const Solution & s)
{
	for (auto& base : s.bases)
	{
		output << '{' << base.x << ',' << base.y << "} ";
	}
	output << s.achievable_points;
	return output;
}


std::list<SimplePoint> Solution::objective_function(std::shared_ptr<Graph> map, const long range)
{
	auto dijkstra = Dijkstra<decltype(map), decltype(this)>::get_dijkstra(map, this);
	this->achievable_points = 0;
	dijkstra->clear_all();
	dijkstra->set_start();
	std::list<SimplePoint> result;
	while(!dijkstra->are_candidates_empty())
	{
		dijkstra->get_proceeded_point();
		dijkstra->add_candidates(range);
	}
	dijkstra->set_direction(Direction::backward);
	dijkstra->clear_visited();
	dijkstra->set_start();
	while(!dijkstra->are_candidates_empty())
	{
		auto& point = dijkstra->get_proceeded_point();
		if((*map)[point].cost + (*map)[point].cost_reversed <= range)
		{
			result.push_back(point);
			this->achievable_points++;
		}
		dijkstra->add_candidates(range);
	}
	return std::move(result);
}