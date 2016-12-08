#include "SA.hpp"
#include <functional>
#include "MainForm.h"

namespace ConsoleApplication1
{


	void SA::generate_first_solution()
	{

	}

	bool SA::run(void)
	{
		std::shared_ptr<Solution> candidate = nei_generator.next();
		long delta;
		while (!Validator::is_allowed(map->get_adjacency_matrix(candidate, max_range)))
		{
			candidate = nei_generator.next();
		}
		candidate->objective_function(map, max_range);
		delta = candidate->achievable_points - actual->achievable_points;
		if (0 < delta)
		{
			actual = candidate;
			nei_generator.generated.clear();
			if (0 > best->achievable_points - actual->achievable_points)
			{
				best = actual;
				this->show_best_solution();
			}
		}
		else
		{
			const double random = static_cast<double> (std::rand()) / RAND_MAX;
			double val_to_check = exp(-static_cast<double>(delta) / temperature);
			if (random < val_to_check)
			{
				actual = candidate;
				nei_generator.generated.clear();
			}
		}
		show_iterations();
		iteration++;
		temperature = alpha*temperature;

		return (max_iterations > iteration);
	}

	void SA::show_best_solution()
	{
		form->SetBestSolution(best);
	}

	void SA::show_iterations()
	{
		form->SetIterations(iteration);
	}

	void SA::prepare_next_iteration()
	{
		temperature = start_temperature;
		iteration = 0;
	}

}
