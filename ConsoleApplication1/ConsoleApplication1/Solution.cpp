#include "Solution.hpp"
#include "Graph.hpp"


void Solution::move(const unsigned int base,const unsigned int where_to_move)
{
	auto it = begin(this->bases);
	for (unsigned int i = 0; i < base; i++)
		++it;
	Base base_to_move = *it;
	this->bases.erase(it);
	switch (where_to_move)
	{
		case 0:
			base_to_move.x--;
			base_to_move.y++;
			break;
		case 1:
			base_to_move.y++;
			break;
		case 2:
			base_to_move.x++;
			base_to_move.y++;
			break;
		case 3:
			base_to_move.x++;
			break;
		case 4:
			base_to_move.x++;
			base_to_move.y--;
			break;
		case 5:
			base_to_move.y--;
			break;
		case 6:
			base_to_move.y--;
			base_to_move.x--;
			break;
		case 7:
			base_to_move.x--;
			break;
		default:
			break;
	}
	this->bases.insert(base_to_move);
}


void Solution::objective_function(Graph& map, const int range)
{
	achievable_points = 0;
	for (auto & line : map.points)
	{
		for (auto & point : line)
		{
			if (range >= point.cost + point.cost_reversed)
			{
				achievable_points++;
			}
		}
	}
	return;
}