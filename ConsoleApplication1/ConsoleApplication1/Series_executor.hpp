#pragma once

#include "SA.hpp"
//potem siê rozbije na cpp
// klasa bêd¹ca pomostem miêdzy gui, a naszym algorytmem
public ref class Series_executor {
	Series_executor(System::String^ gui_series, System::String^ gui_iterations, System::Windows::Forms::ListBox::ObjectCollection^ gui_best_solution) {
		this->series = gui_series;
		this->gui_iterations = gui_iterations;
		this->gui_best_solution = gui_best_solution;
	}
	
	void init(double temperature, double alpha, int max_iterations, int x, int y, System::Drawing::Image^ map_image) {
		this->sa = new SA(temperature, alpha, max_iterations, x, y, Graph(map_image), gui_iterations, gui_best_solution);
	}

	SA* sa;
	System::String^ series;
	System::String^ gui_iterations;
	System::Windows::Forms::ListBox::ObjectCollection^ gui_best_solution;
	void next_series();
	~Series_executor() {
		this->!Series_executor();
	}
	!Series_executor() {
		if (sa != nullptr) {
			delete sa;
		}
	}
};