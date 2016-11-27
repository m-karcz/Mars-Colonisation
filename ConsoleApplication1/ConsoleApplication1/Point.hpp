#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include "Node.hpp"

struct Point { //punkt na mapie
	bool visited; //czy byl odwiedzony dla algorytmu
	long cost = INT_MAX; //koszt sumaryczny
	long cost_reversed = INT_MAX;
	std::vector<Node> nodes; //talbica dostepnych punktow
	std::vector<Node> nodes_reversed;
};