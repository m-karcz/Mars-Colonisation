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
	Graph map;
	gcroot<System::String^> gui_iterations; //label w gui, gdzie bêdzie wyœwietlana liczba przebytych iteracji
	gcroot<System::Windows::Forms::ListBox::ObjectCollection^> gui_best_solution; //lista punktow w gui, ktore sa najlepszym aktualnym rozwiazaniem
	

	SA(double temperature, const double alpha, const unsigned int max_iterations, int x, int y, Graph & map, System::String^ gui_iterations, System::Windows::Forms::ListBox::ObjectCollection^ gui_best_solution);
	void generate_first_solution(); //wygenerowanie pierwszego rozwi¹zania w konstruktorze
	bool run(void);
};

