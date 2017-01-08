#pragma once

#include "Dijkstra.hpp"

ref class XY
{
	public: XY(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
    public: XY(const SimplePoint& sp)
    {
		this->x = sp.x;
		this->y = sp.y;
    }
	public: int x;
	public: int y;
};