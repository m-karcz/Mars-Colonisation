#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include "Edge.hpp"

struct Point { //punkt na mapie
	bool visited = false; //czy byl odwiedzony dla algorytmu
	long cost = LONG_MAX; //koszt sumaryczny
	long cost_reversed = LONG_MAX;
	std::vector<Edge> edges; //talbica dostepnych punktow
	std::vector<Edge> edges_reversed;

	Point(std::vector<Edge> edgess, std::vector<Edge> edges_reversedd) : edges(edgess.begin(), edgess.end()), edges_reversed(edges_reversedd.begin(), edges_reversedd.end()) {}
};