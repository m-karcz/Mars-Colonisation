#pragma once

#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>

typedef std::vector<std::vector<bool>> adj_matrix;

struct Node { //polaczenie
	int cost; //koszt polaczenia do xy
	int x;
	int y;
};

struct Point { //punkt na mapie
	bool visited; //czy byl odwiedzony dla algorytmu
	long cost = INT_MAX; //koszt sumaryczny
	long cost_reversed = INT_MAX;
	std::vector<Node> nodes; //talbica dostepnych punktow
	std::vector<Node> nodes_reversed;
};

struct Graph { //graf
	std::vector<std::vector<Point>> points;
	adj_matrix get_adjacency_matrix(Solution & actual);
};

struct Validator
{
	static bool is_allowed(adj_matrix & matrix);
};

struct Base { //baza
	int x;
	int y;
};

struct Solution {
	long achievable_points = 0;
	std::vector<Base> bases;

	std::vector<Base> get_neighbourhood(Graph & map);
	void objective_function(Graph & map);
};

struct Neighbourhood_generator
{
	Solution & actual;
	std::set<std::vector<Base>> generated;

	Neighbourhood_generator(Solution & actual);
	Solution next();
};

struct SA
{
	Solution actual;
	Solution best;
	Neighbourhood_generator nei_generator;
	double temperature;
	const unsigned int max_iterations;
	unsigned int iteration;
	const double alpha;
	Graph map;

	SA(double temperature, const double alpha, const unsigned int max_iterations, Solution & actual, Graph & map);
	bool run(void);
};

bool SA::run(void)
{
	bool result;
	Solution candidate = nei_generator.next();
	long delta;
	while (!Validator::is_allowed(map.get_adjacency_matrix(candidate)))
	{
		candidate = nei_generator.next();
	}
	candidate.objective_function(map);
	delta = candidate.achievable_points - actual.achievable_points;
	if (0 < delta)
	{
		actual = candidate;
		if (0 > best.achievable_points - actual.achievable_points)
		{
			best = actual;
		}
	}
	else
	{
		//dodac srand na poczatku !!!!!!!!!!!!oneone
		const double random = static_cast<double> (std::rand()) / RAND_MAX;
		double val_to_check = exp(-static_cast<double>(delta) / temperature);
		if (random < val_to_check)
		{
			actual = candidate;
		}
	}

	iteration++;
	temperature = alpha*temperature;

	return (max_iterations > iteration);
}