#include "SA.hpp"
/*
bool SA::run(void)
{
	Solution candidate = nei_generator.next();
	long delta;
	while (!Validator::is_allowed(map.get_adjacency_matrix(candidate)))
	{
		candidate = nei_generator.next();
	}
	candidate.objective_function(map, max_range);
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
}*/