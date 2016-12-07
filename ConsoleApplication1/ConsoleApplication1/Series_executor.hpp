#pragma once

#include "SA.hpp"
#include <memory>
//potem siê rozbije na cpp
// klasa bêd¹ca pomostem miêdzy gui, a naszym algorytmem
public ref class Series_executor {
public:
	Series_executor(System::Windows::Forms::Label^ gui_series, System::Windows::Forms::Label^ gui_iterations, System::Windows::Forms::ListBox::ObjectCollection^ gui_best_solution) {
		this->series = gui_series;
		this->gui_iterations = gui_iterations;
		this->gui_best_solution = gui_best_solution;
	}
	
	void init(double temperature, double alpha, int max_iterations, int x, int y, int amount, System::Drawing::Image^ map_image, int max_slope) {
		auto initial_solution = Solution::generate_initial(x, y, amount);
		this->sa = new SA(temperature, alpha, max_iterations, initial_solution, std::shared_ptr<Graph>(new Graph(map_image, max_slope)), gui_iterations, gui_best_solution);
	}

	SA* sa;
	System::Windows::Forms::Label^ series;
	System::Windows::Forms::Label^ gui_iterations;
	System::Windows::Forms::ListBox::ObjectCollection^ gui_best_solution;

	void next_series() {
		for (int i = 0; i < 100; i++) {
			sa->run();
		}
	}
	void show_series_number() {
	
	}
	
	~Series_executor() {
		this->!Series_executor();
	}
	!Series_executor() {
		if (sa != nullptr) {
			delete sa;
		}
	}
};