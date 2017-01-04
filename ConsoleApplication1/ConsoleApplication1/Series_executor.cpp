#include "Series_executor.hpp"
#include "MainForm.h"
#include <chrono>

using namespace std::chrono;

namespace ConsoleApplication1
{

	void Series_executor::serie()
	{
		form->SetRun(false);
		sa->prepare_next_iteration();
		/*for (int i = 0; i < 200; i++) {
			sa->run();
		}*/
		auto t1 = high_resolution_clock::now();
		while(sa->run() && !form->IsDisposed){}
		if(!form->IsDisposed)
		{
			form->SetRun(true);
		}
		std::cout << "Serie time: " << duration_cast<seconds>(high_resolution_clock::now() - t1).count() << "s" << std::endl;
	}
	void Series_executor::next_series() {
		System::Threading::Thread^ t = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &Series_executor::serie));
		t->Start();
	}
}