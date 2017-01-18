#pragma once

#include "SA.hpp"
#include <memory>
#include <string>


namespace MarsColonisation {
	ref class MainForm;
	public ref class Series_executor {
	public:
		Series_executor(System::Windows::Forms::Label^ gui_series, System::Windows::Forms::Label^ gui_iterations, System::Windows::Forms::ListBox^ gui_best_solution, MainForm^ form) {
			this->series = gui_series;
			this->gui_iterations = gui_iterations;
			this->gui_best_solution = gui_best_solution;
			this->form = form;
		}
		void init(double temperature, double alpha, int x, int y, int amount, System::Drawing::Image^ map_image, int max_slope, int max_range)
		{
			init(temperature, alpha, x, y, amount, map_image, max_slope, max_range, "output.txt");
		}
		void init(double temperature, double alpha, int x, int y, int amount, System::Drawing::Image^ map_image, int max_slope, int max_range, std::string file_name) {
			auto initial_solution = Solution::generate_initial(x, y, amount);
			this->sa = new SA(temperature, alpha, initial_solution, std::shared_ptr<Graph>(new Graph(map_image, max_slope)), form, max_range, file_name);
		}
		MainForm^ form;
		SA* sa;
		System::Windows::Forms::Label^ series;
		System::Windows::Forms::Label^ gui_iterations;
		System::Windows::Forms::ListBox^ gui_best_solution;


		long best_achievable_points = 0;
		char without_improvement = 0;
		void next_series();
		void serie();	

		~Series_executor() {
			this->!Series_executor();
		}
		!Series_executor() {
			if (sa != nullptr) {
				delete sa;
			}
		}
	};

}