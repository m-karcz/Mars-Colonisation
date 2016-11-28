#pragma once
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>

struct Base 
{ //baza
	int x;
	int y;

	Base(int xx, int yy) :x(xx), y(yy) {}
	Base(){ x = 0; y = 0; }
};
