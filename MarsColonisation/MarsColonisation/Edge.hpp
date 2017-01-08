#pragma once
#include "stdafx.h"
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>

struct Edge { //polaczenie
	int cost; //koszt polaczenia do xy
	int x;
	int y;
	Edge(int xx, int yy, int costt) :x(xx), y(yy), cost(costt) {}
};
