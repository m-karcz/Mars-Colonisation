#pragma once

#include "SA.hpp"
#include <memory>

//namespace ConsoleApplication1
//{
namespace ConsoleApplication1 {
	ref class MainForm;
	//}

	//potem siê rozbije na cpp
	// klasa bêd¹ca pomostem miêdzy gui, a naszym algorytmem
	public ref class Series_executor {
	public:
		Series_executor(System::Windows::Forms::Label^ gui_series, System::Windows::Forms::Label^ gui_iterations, System::Windows::Forms::ListBox^ gui_best_solution, MainForm^ form) {
			this->series = gui_series;
			this->gui_iterations = gui_iterations;
			this->gui_best_solution = gui_best_solution;
			this->form = form;
		}

		void init(double temperature, double alpha, int max_iterations, int x, int y, int amount, System::Drawing::Image^ map_image, int max_slope) {
			auto initial_solution = Solution::generate_initial(x, y, amount);
			this->sa = new SA(temperature, alpha, max_iterations, initial_solution, std::shared_ptr<Graph>(new Graph(map_image, max_slope)), gui_iterations, gui_best_solution, form);
			//gui_best_solution->Invoke(Add123);
		}
		MainForm^ form;
		SA* sa;
		System::Windows::Forms::Label^ series;
		System::Windows::Forms::Label^ gui_iterations;
		System::Windows::Forms::ListBox^ gui_best_solution;

		void next_series();
		void serie();
		void show_series_number() {

		}

		/*void test(System::Windows::Forms::Control^ control)
		{
			control->Invoke();
		}*/



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