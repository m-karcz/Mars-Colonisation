#include "SA.hpp"
#include <functional>
#include <iostream>
#include "MainForm.h"
#include <cmath>


bool SA::is_stationary()
{
	bool result = false;
	if (history_size == of_history.size())
	{
		result = true;
		int val = of_history[0];
		for (int i : of_history)
		{
			if (i != val)
			{
				result = false;
				break;
			}
		}
	}
	return result;
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
			nei_generator.better = true;
			this->improved++;
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
			this->accepted++;
#ifdef SA_DEBUG
			std::cout << "Przyjalem gorsze: " << *actual << std::endl;
#endif SA_DEBUG
		}
		else
		{
			this->rejected++;
#ifdef SA_DEBUG
			std::cout << "Odrzucilem gorsze rozwiazanie: " << *candidate << std::endl;
#endif SA_DEBUG
		}
	}
	this->show_best_solution();
	this->plot_objective_function();
	this->save_objective_funtion();
	show_iterations();
	iteration++;
	temperature = alpha*temperature;
	nei_generator.temp_actualize(temperature);
	add_of_history(best->achievable_points);

	return (!is_stationary() || (temperature > min_temp));
}

void SA::add_of_history(int val)
{
	of_history.push_back(val);
	if (history_size < of_history.size())
	{
		of_history.erase(of_history.begin());
	}
}

auto SA::get_best_achievable_points() -> decltype(best->achievable_points)
{
	return this->best->achievable_points;
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
	this->prepare_next_iteration(this->start_temperature, this->alpha);
}
void SA::prepare_next_iteration(double new_temp, double new_alpha)
{
	//std::cout << "Accepted: " << accepted << ",Rejected:" << rejected << ",Improved:" << improved << std::endl;
	calculate_new_parameters();
	this->accepted = 0;
	this->rejected = 0;
	this->improved = 0;
	this->alpha = new_alpha;
	this->temperature = new_temp;
	this->iteration = 0;
}

void SA::draw_best_solution(std::shared_ptr<Solution> solution, std::list<SimplePoint>&& range)
{
	this->form->DrawBestSolution(solution, std::move(range));
}
void SA::plot_objective_function()
{
	this->form->PlotObjectiveFunction(actual->achievable_points, best->achievable_points);
}

void SA::save_objective_funtion()
{
	file << actual->achievable_points << "\t" << best->achievable_points << "\t" << *actual << "\t" << *best << std::endl;
}

void SA::calculate_new_parameters()
{
	/*
	 *	accepted > 1.5 rejected -> zniejszyc temp
	 *	1.5 accepted < rejected -> zwiekszyc temp
	 *	
	 *	brak improved -> zwiekszyc delte
	 */
	if (1.5*accepted > rejected)
		this->start_temperature /= 5.0;
	else if (2.5*accepted < rejected)
		this->start_temperature *= 5.0;

	if (improved == 0)
		this->alpha = (this->alpha + 1.0) / 2.0;

	this->form->ShowTempAndAlpha(start_temperature, alpha);
	
}
