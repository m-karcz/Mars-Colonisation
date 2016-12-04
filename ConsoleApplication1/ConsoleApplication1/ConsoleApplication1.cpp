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

#include "stdafx.h"
using namespace System;
[System::STAThread]
int main(array<System::String ^> ^args)
{
	//WinExec("matlab -r test", SW_SHOWNORMAL);
	std::srand(std::time(nullptr));
    Console::WriteLine(L"tutaj bedzie latwo debugowac, np. coutem");
	//test
	System::Drawing::Image^ newImage = System::Drawing::Image::FromFile("img.jpg");
	std::cout << "dupa1" << std::endl;
	Graph map(newImage);
	std::cout << "dupa2" << std::endl;
	Base base;
	Solution solution;
	solution.bases.insert(base);
	solution.objective_function(map, 10);
	int result = solution.achievable_points;

	std::cout << "Odiagalnych punktow: " << result << std::endl;

	//end of test
	ConsoleApplication1::MainForm myForm;
	myForm.ShowDialog();
	Console::ReadKey();
    return 0;
}
