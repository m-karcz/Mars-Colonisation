#include "SA.hpp"

void SA::generate_first_solution()
{

}

bool SA::run(void)
{
	max_range = 40;  //<-----to wywalic bo chwilowe
	std::shared_ptr<Solution> candidate = nei_generator.next();
	System::Console::WriteLine("iteruje");
	long delta;
	while (!Validator::is_allowed(map->get_adjacency_matrix(candidate, max_range)))
	{
		candidate = nei_generator.next();
		//System::Console::WriteLine("szukam dopuszczalnego");
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
	this->gui_best_solution->Clear();
	for (auto& base : best->bases) {
		gui_best_solution->Add(base.x.ToString()+", "+base.y.ToString());
	}
}

void SA::show_iterations()
{
	gui_iterations->Text = ((System::Int32::Parse(gui_iterations->Text)+1).ToString());
}
