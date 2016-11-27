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
	unsigned int max_range;
	const double alpha;
	Graph map;

	SA(double temperature, const double alpha, const unsigned int max_iterations, Solution & actual, Graph & map);
	bool run(void);
};

