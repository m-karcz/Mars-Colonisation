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
#include <string>

namespace ConsoleApplication1 {
	ref class MainForm;
}

struct SA
{
	std::shared_ptr<Solution> actual;
	std::shared_ptr<Solution> best;
	Neighbourhood_generator nei_generator;
	double temperature;
	double start_temperature;
	unsigned int iteration = 0;
	double alpha;
	const double min_temp = 0.4;
	int max_range;
	int improved; //liczba polepszeñ wartoœci achievable_points w actualu
	int accepted; //liczba zaakceptowanych pogorszeñ wartoœci achievable_points w actualu
	int rejected; //liczba odrzuconych pogorszeñ wartoœci achievable_points w actualu
	std::shared_ptr<Graph> map;
	gcroot<ConsoleApplication1::MainForm^> form;
	bool first = true;
	const std::string file_name = "output.txt";


	SA(double temperature, const double alpha, std::shared_ptr<Solution> initial, std::shared_ptr<Graph> map, ConsoleApplication1::MainForm^ form, int max_range) : temperature(temperature), alpha(alpha), actual(initial), best(initial), map(map), nei_generator(map, start_temperature), form(form), start_temperature(temperature), max_range(max_range) {}
	bool run(void);
	void prepare_next_iteration(); //ustawia temperature przed kolejn¹ iteracj¹
	void prepare_next_iteration(double new_temp, double new_alpha);
	void show_best_solution(); //ustawia aktualne rozwi¹zanie w gui
	void show_iterations(); //inkrementuje aktualn¹ iloœæ iteracji w gui
	void draw_best_solution(std::shared_ptr<Solution> solution, std::list<SimplePoint>&& range); //maluje aktualne rozwiazanie na mapie w gui
	void plot_objective_function();
	void save_objective_funtion();
};
