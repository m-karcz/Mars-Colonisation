#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include "Edge.hpp"

struct Point { //punkt na mapie
	bool visited = false; //czy byl odwiedzony dla algorytmu
	long cost = LONG_MAX/3; //koszt sumaryczny
	long cost_reversed = LONG_MAX/3;
	std::vector<Edge> edges; //talbica dostepnych punktow
	std::vector<Edge> edges_reversed;
	Point() {};
	Point(const Point& other)
	{
		this->visited = other.visited;
		this->cost = other.cost;
		this->cost_reversed = other.cost_reversed;
		this->edges = std::vector<Edge>(other.edges.begin(), other.edges.end());
		this->edges_reversed = std::vector<Edge>(other.edges_reversed.begin(), other.edges_reversed.end());
	}

	Point(std::vector<Edge> edges, std::vector<Edge> edges_reversed) : edges(edges.begin(), edges.end()), edges_reversed(edges_reversed.begin(), edges_reversed.end()) {}
};