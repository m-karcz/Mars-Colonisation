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
#include <Windows.h>

#include "stdafx.h"
using namespace System;
[System::STAThread]
int main(array<System::String ^> ^args)
{
	//WinExec("matlab -r test", SW_SHOWNORMAL);
    Console::WriteLine(L"tutaj bedzie latwo debugowac, np. coutem");
	ConsoleApplication1::MainForm myForm;
	myForm.ShowDialog();
	Console::ReadKey();
    return 0;
}
