#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include"Solution.hpp"
#include"Neighbourhood_generator.hpp"
#include"Graph.hpp"
#include"Validator.hpp"
#include <gcroot.h>

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
	Graph& map;
	gcroot<System::Windows::Forms::Label^> gui_iterations; //label w gui, gdzie b�dzie wy�wietlana liczba przebytych iteracji
	gcroot<System::Windows::Forms::ListBox::ObjectCollection^> gui_best_solution; //lista punktow w gui, ktore sa najlepszym aktualnym rozwiazaniem
	

	SA(double temperature, const double alpha, const unsigned int max_iterations, Solution initial, Graph & map, System::Windows::Forms::Label^ gui_iterations, System::Windows::Forms::ListBox::ObjectCollection^ gui_best_solution) : temperature(temperature), alpha(alpha), max_iterations(max_iterations), actual(initial), best(initial),map(map), gui_iterations(gui_iterations), gui_best_solution(gui_best_solution), nei_generator(initial) {}
	void generate_first_solution(); //wygenerowanie pierwszego rozwi�zania w konstruktorze
	bool run(void);
	void show_best_solution(); //ustawia aktualne rozwi�zanie w gui
	void show_iterations(); //inkrementuje aktualn� ilo�� iteracji w gui
};

