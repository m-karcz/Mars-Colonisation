#include "Series_executor.hpp"
#include "MainForm.h"


namespace ConsoleApplication1
{

	void Series_executor::serie()
	{
		form->SetRun(false);
		sa->prepare_next_iteration();
		for (int i = 0; i < 1000; i++) {
			sa->run();
		}
		form->SetRun(true);
	}
	void Series_executor::next_series() {
		System::Threading::Thread^ t = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &Series_executor::serie));
		t->Start();
	}
}