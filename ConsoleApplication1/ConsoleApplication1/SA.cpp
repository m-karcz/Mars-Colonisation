#include "SA.hpp"
#include <functional>
#include <iostream>
#include "MainForm.h"



void SA::generate_first_solution()
{

}

bool SA::run(void)
{
	std::shared_ptr<Solution> candidate = nei_generator.next(actual);
	long delta;
	while (!Validator::is_allowed(map->get_adjacency_matrix(candidate, max_range)))
	{
		candidate = nei_generator.next(actual);
#ifdef SA_DEBUG
		System::Console::WriteLine("odrzucam niepoprawne");
#endif
	}
	auto result = candidate->objective_function(map, max_range);
	delta = candidate->achievable_points - actual->achievable_points;
	if (0 < delta)
	{
		actual = candidate;
		nei_generator.generated.clear();
		if (0 > best->achievable_points - actual->achievable_points)
		{

			best = actual;
			this->show_best_solution();
			this->draw_best_solution(best, std::move(result));

		}
#ifdef SA_DEBUG
		std::cout << "Przyjalem lepsze: " << *actual << std::endl;
#endif SA_DEBUG
	}
	else
	{
		const double random = static_cast<double> (std::rand()) / RAND_MAX;
		double val_to_check = exp(-(static_cast<double>(-delta) / temperature));
		if (random < val_to_check)
		{
			actual = candidate;
			nei_generator.generated.clear();
#ifdef SA_DEBUG
			std::cout << "Przyjalem gorsze: " << *actual << std::endl;
		}
		else
		{
			std::cout << "Odrzucilem gorsze rozwiazanie: " << *candidate << std::endl;
#endif SA_DEBUG
		}
	}
	this->show_best_solution();
	this->plot_objective_function( actual ,best, iteration);
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
void SA::draw_best_solution(std::shared_ptr<Solution> solution, std::list<std::pair<int, int>>&& range)
{
	this->form->DrawBestSolution(solution, std::move(range));
}
void SA::plot_objective_function(std::shared_ptr<Solution> actual, std::shared_ptr<Solution> best, const unsigned int iteration)
{
	this->form->PlotObjectiveFunction(actual, best, iteration);
}