#include "Solution.hpp"
#include "Graph.hpp"
#include <vector>
#include <list>
#include <algorithm>

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

Solution::Solution(const Solution & pattern)
{
	bases = pattern.bases;
	achievable_points = pattern.achievable_points;
}


void Solution::objective_function(Graph& map, const long range)
{
	
	//struktura, ktora posiada w sobie wspolrzedne - upraszcza i przyspiesza generowanie listy kandydatow do nastepnej iteracji
	struct SimplePoint 
	{
		SimplePoint(int x, int y) : x(x), y(y) {}
		SimplePoint(Edge edge) :x(edge.x), y(edge.y) {}
		int x;
		int y;
		bool operator==(const SimplePoint& rhs) const { return (this->x == rhs.x) && (this->y == rhs.y); }
	};
	//funkcja, ktora jest uzywana pozniej do sortowania listy kandydatow
	auto comparator = [&map](const SimplePoint& b1, const SimplePoint& b2)->bool 
	{
		return ((map.points[b1.y][b1.x].cost) < (map.points[b2.y][b2.x].cost));
	};
	
	//przeiterowanie po wszystkich bazach - Dijkstra od bazy
	for (auto& proceeded_base : bases)
	{
		map.clear_visited();
		std::list<SimplePoint> candidates; //lista kandydatow do nastepnej iteracji algorytmu Dijkstry
		map.points[proceeded_base.y][proceeded_base.x].cost = 0; //ustawienie punktu startowego(bazy)
		map.points[proceeded_base.y][proceeded_base.x].visited = true;
		candidates.emplace_front(proceeded_base.x, proceeded_base.y);
		while ( !candidates.empty() ) 
		{
			SimplePoint proceeded_point = candidates.front(); //procedowanie na punkcie z na punkcie z najmniejszym kosztem
			candidates.pop_front();
			Point& point = map.points[proceeded_point.y][proceeded_point.x];
			point.visited = true;
			for (auto& edge : point.edges) 
			{ //ustawienie na górnego ograniczenia kosztu na dostêpnych punktach
				if (!map[edge].visited) 
				{
					map[edge].cost = std::min(map[edge].cost, point.cost + static_cast<long>(edge.cost));
					if (std::find(begin(candidates), end(candidates), edge) == end(candidates))
					{
						candidates.emplace_back(SimplePoint(edge));
					}
					
				}
			}
			//przesortowanie punktów celem wy³onienia punktu z najni¿szym górnym ograniczeniem do nastêpnej iteracji
			candidates.sort(comparator);
		}
	}
	

	//przeiterowanie po wszystkich bazach - Dijkstra do bazy
	for (auto& proceeded_base : bases)
	{
		map.clear_visited();
		std::list<SimplePoint> candidates; //lista kandydatow do nastepnej iteracji algorytmu Dijkstry
		map.points[proceeded_base.y][proceeded_base.x].cost_reversed = 0; //ustawienie punktu startowego(bazy)
		map.points[proceeded_base.y][proceeded_base.x].visited = true;
		candidates.emplace_front(proceeded_base.x, proceeded_base.y);
		while (!candidates.empty())
		{
			SimplePoint proceeded_point = candidates.front(); //procedowanie na punkcie z na punkcie z najmniejszym kosztem
			candidates.pop_front();
			Point& point = map.points[proceeded_point.y][proceeded_point.x];
			point.visited = true;
			for (auto& edge : point.edges_reversed)
			{ //ustawienie na górnego ograniczenia kosztu na dostêpnych punktach
				if (!map[edge].visited)
				{
					map[edge].cost_reversed = std::min(map[edge].cost_reversed, point.cost_reversed + static_cast<long>(edge.cost));
					if (std::find(begin(candidates), end(candidates), edge) == end(candidates))
					{
						candidates.emplace_back(SimplePoint(edge));
					}

				}
			}
			//przesortowanie punktów celem wy³onienia punktu z najni¿szym górnym ograniczeniem do nastêpnej iteracji
			candidates.sort(comparator);
		}
	}


	//przeliczenie dostepnych punktow
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