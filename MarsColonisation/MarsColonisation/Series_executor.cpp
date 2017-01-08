#include "Series_executor.hpp"
#include "MainForm.h"
#include <chrono>

using namespace std::chrono;

namespace MarsColonisation
{

	void Series_executor::serie()
	{
		form->SetRun(false);
		auto tx = high_resolution_clock::now();
	//	while (this->without_improvement < 10)
		//{
			sa->prepare_next_iteration();
			form->IncrementSeries();
			auto t1 = high_resolution_clock::now();
			while (sa->run() && !form->IsDisposed) {}
#ifdef BENCHMARKS
			std::cout << "Serie time: " << duration_cast<seconds>(high_resolution_clock::now() - t1).count() << "s" << std::endl;
#endif
#ifdef AUTOMATE_IT
			System::Console::WriteLine(series->Text + ":" + sa->get_best_achievable_points().ToString());
#endif
		/*	if (sa->get_best_achievable_points() > this->best_achievable_points)
			{
				this->best_achievable_points = sa->get_best_achievable_points();
				this->without_improvement = 0;
			}
			else
			{
				this->without_improvement++;
			}
		}*/
		if (!form->IsDisposed)
		{
			form->SetRun(true);
		}
#ifdef AUTOMATE_IT
		std::cout << "Run time: " << duration_cast<seconds>(high_resolution_clock::now() - tx).count() << "s" << std::endl;
		this->form->CloseForAutomation();
#endif
	}
	void Series_executor::next_series() {
		System::Threading::Thread^ t = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &Series_executor::serie));
		t->Start();
	}
}
