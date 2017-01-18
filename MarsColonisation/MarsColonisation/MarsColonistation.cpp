// MarsColonisation.cpp : main project file.

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
	auto x = static_cast<unsigned int>(std::time(0));
	std::srand(x);
	MarsColonisation::MainForm myForm(args);
	myForm.ShowDialog();
    return 0;
}
