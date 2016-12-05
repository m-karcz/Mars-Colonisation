#pragma once

#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include <gcroot.h>

#include "Point.hpp"
#include "Solution.hpp"

typedef std::vector<std::vector<bool> > adj_matrix;
struct Graph
{ //graf
	Graph()=delete;
	Graph(const Graph& other) = delete;
	Graph(System::Drawing::Image^ img, int max_slope);
	std::vector<std::vector<Point>> points;
	void clear(); //ustawia costy w pointsach
	void clear_visited();
	adj_matrix get_adjacency_matrix(std::shared_ptr<Solution> actual, long range);
	Point& operator[](const Edge& edge) { return points[edge.y][edge.x]; }
	
};