#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include "Edge.hpp"

struct Point { //punkt na mapie
	bool visited = false; //czy byl odwiedzony dla algorytmu
	bool visited_reverse = false;	//odwiedzony przez algorytm odwrotu
	long cost = LONG_MAX; //koszt sumaryczny
	long cost_reversed = LONG_MAX;
	std::vector<Edge> edges; //talbica dostepnych punktow
	std::vector<Edge> edges_reversed;

	Point(std::vector<Edge> edges, std::vector<Edge> edges_reversed) : edges(edges.begin(), edges.end()), edges_reversed(edges_reversed.begin(), edges_reversed.end()) {}
};