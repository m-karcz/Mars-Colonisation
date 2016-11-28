#pragma once

#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>

#include "Point.hpp"
#include "Solution.hpp"

typedef std::vector<std::vector<bool> > adj_matrix;
struct Graph
{ //graf
	Graph();
	Graph(System::Drawing::Image^ img);
	std::vector<std::vector<Point>> points;
	void clear(); //ustawia costy w pointsach
	adj_matrix get_adjacency_matrix(Solution & actual);
};