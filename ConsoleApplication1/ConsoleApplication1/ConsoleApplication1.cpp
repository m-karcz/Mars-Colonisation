// ConsoleApplication1.cpp : main project file.

#include "Base.hpp"
#include "Graph.hpp"
#include "Neighbourhood_generator.hpp"
#include "Edge.hpp"
#include "Point.hpp"
#include "SA.hpp"
#include "Solution.hpp"
#include "Validator.hpp"
#include "MainForm.h"
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <iostream>
#include <Windows.h>

#include "stdafx.h"
using namespace System;
[System::STAThread]
int main(array<System::String ^> ^args)
{
	//WinExec("matlab -r test", SW_SHOWNORMAL);
	auto x = static_cast<unsigned int>(std::time(0));
	std::srand(x);
	System::Diagnostics::Debug::WriteLine(std::rand());
	System::Diagnostics::Debug::WriteLine(std::rand());
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	ConsoleApplication1::MainForm myForm;
#ifdef AUTOMATE_IT
	if(myForm.SetStart(args))
	{
		myForm.ShowDialog();
	}
#else
	myForm.ShowDialog();
#endif
    return 0;
}
