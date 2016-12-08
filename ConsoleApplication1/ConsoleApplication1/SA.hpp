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
#include <memory>

namespace ConsoleApplication1
{

	ref class MainForm;

	struct SA
	{
		std::shared_ptr<Solution> actual;
		std::shared_ptr<Solution> best;
		Neighbourhood_generator nei_generator;
		double temperature;
		double start_temperature;
		const unsigned int max_iterations;
		unsigned int iteration=0;
		const double alpha;
		int max_range;
		std::shared_ptr<Graph> map;
		gcroot<MainForm^> form;
		gcroot<System::Windows::Forms::Label^> gui_iterations; //label w gui, gdzie bêdzie wyœwietlana liczba przebytych iteracji
		gcroot<System::Windows::Forms::ListBox^> gui_best_solution; //lista punktow w gui, ktore sa najlepszym aktualnym rozwiazaniem


		SA(double temperature, const double alpha, const unsigned int max_iterations, std::shared_ptr<Solution> initial, std::shared_ptr<Graph> map, System::Windows::Forms::Label^ gui_iterations, System::Windows::Forms::ListBox^ gui_best_solution, MainForm^ form, int max_range) : temperature(temperature), alpha(alpha), max_iterations(max_iterations), actual(initial), best(initial), map(map), gui_iterations(gui_iterations), gui_best_solution(gui_best_solution), nei_generator(initial, map), form(form), start_temperature(temperature), max_range(max_range) {}
		void generate_first_solution(); //wygenerowanie pierwszego rozwi¹zania w konstruktorze
		bool run(void);
		void prepare_next_iteration(); //ustawia temperature przed kolejn¹ iteracj¹
		void show_best_solution(); //ustawia aktualne rozwi¹zanie w gui
		void show_iterations(); //inkrementuje aktualn¹ iloœæ iteracji w gui
	};

}