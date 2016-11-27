#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include"Solution.hpp"
#include"Neighbourhood_generator.hpp"
#include"Graph.hpp"
#include"Validator.hpp"

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