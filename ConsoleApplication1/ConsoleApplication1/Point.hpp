#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>

struct Edge;

struct Point { //punkt na mapie
	bool visited; //czy byl odwiedzony dla algorytmu
	long cost = INT_MAX; //koszt sumaryczny
	long cost_reversed = INT_MAX;
	std::vector<Edge> edges; //talbica dostepnych punktow
	std::vector<Edge> edges_reversed;
};