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
	bool operator==(const Base& rhs)const { return (this->x == rhs.x) && (this->y == rhs.y); }
	bool operator<(const Base& rhs)const { return this->x < rhs.x ? true : (this->x > rhs.x ? false : this->y < rhs.y); }
};
