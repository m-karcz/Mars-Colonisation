#include "Solution.hpp"
#include "Graph.hpp"


void Solution::move(const unsigned int base,const unsigned int where_to_move)
{
	switch (where_to_move)
	{
		case 0:
			bases[base].x--;
			bases[base].y++;
			break;
		case 1:
			bases[base].y++;
			break;
		case 2:
			bases[base].x++;
			bases[base].y++;
			break;
		case 3:
			bases[base].x++;
			break;
		case 4:
			bases[base].x++;
			bases[base].y--;
			break;
		case 5:
			bases[base].y--;
			break;
		case 6:
			bases[base].y--;
			bases[base].x--;
			break;
		case 7:
			bases[base].x--;
			break;
		default:
			break;
	}
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