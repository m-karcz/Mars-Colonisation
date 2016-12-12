#include "Solution.hpp"
#include "Graph.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <chrono>
#include "MainForm.h"

using namespace std::chrono;


void Solution::move_rand(int height, int width)
{
	//std::vector<Base> bases(this->bases.begin(), this->bases.end());
	for (int i = 1; i < bases.size(); i++)
	{
		bases[i].x = std::rand() % width + 1;
		bases[i].y = std::rand() % height + 1;
	}
	//this->bases = std::multiset<Base>(bases.begin(), bases.end());
}

void Solution::move(Base& base2move, const unsigned int where_to_move)
{
	/*auto it = begin(this->bases);
	for (unsigned int i = 0; i < base; i++)
		++it;
	Base base_to_move = *it;
	this->bases.erase(it);*/
	//std::cout << "Before: " << *this << std::endl;
	//std::vector<Base> bases(this->bases.begin(), this->bases.end());
	//Base& base_to_move = bases[base];
	auto base_to_move = std::find(bases.begin(), bases.end(), base2move);
	switch (where_to_move)
	{
	case 0:
		base_to_move->x--;
		base_to_move->y++;
		break;
	case 1:
		base_to_move->y++;
		break;
	case 2:
		base_to_move->x++;
		base_to_move->y++;
		break;
	case 3:
		base_to_move->x++;
		break;
	case 4:
		base_to_move->x++;
		base_to_move->y--;
		break;
	case 5:
		base_to_move->y--;
		break;
	case 6:
		base_to_move->y--;
		base_to_move->x--;
		break;
	case 7:
		base_to_move->x--;
		break;
	default:
		break;
	}
	//this->bases.insert(base_to_move);
	//this->bases = std::multiset<Base>(bases.begin(), bases.end());
	//std::cout << "After: " << *this << std::endl;
}

Solution::Solution(const Solution & pattern)
{
	bases = std::vector<Base>(pattern.bases.begin(), pattern.bases.end());
	achievable_points = pattern.achievable_points;
}

std::ostream & operator<< (std::ostream & output, const Solution & s)
{
	for (auto& base : s.bases)
	{
		output << '{' << base.x << ',' << base.y << "} ";
	}
	output << s.achievable_points;
	return output;
}


std::list<std::pair<int,int>> Solution::objective_function(std::shared_ptr<Graph> map, const long range)
{
	//struktura, ktora posiada w sobie wspolrzedne - upraszcza i przyspiesza generowanie listy kandydatow do nastepnej iteracji
	auto t1 = high_resolution_clock::now();
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
		return ((map->points[b1.y][b1.x].cost) < (map->points[b2.y][b2.x].cost));
	};

	map->clear();

	//przeiterowanie po wszystkich bazach - Dijkstra od bazy
	for (auto& proceeded_base : bases)
	{
		map->clear_visited();
		std::list<SimplePoint> candidates; //lista kandydatow do nastepnej iteracji algorytmu Dijkstry
		map->points[proceeded_base.y][proceeded_base.x].cost = 0; //ustawienie punktu startowego(bazy)
		map->points[proceeded_base.y][proceeded_base.x].visited = true;
		candidates.emplace_front(proceeded_base.x, proceeded_base.y);
		while (!candidates.empty())
		{
			SimplePoint proceeded_point = candidates.front(); //procedowanie na punkcie z na punkcie z najmniejszym kosztem
			candidates.pop_front();
			Point& point = map->points[proceeded_point.y][proceeded_point.x];
			point.visited = true;
			for (auto& edge : point.edges)
			{ //ustawienie na górnego ograniczenia kosztu na dostêpnych punktach
				if (!(*map)[edge].visited)
				{
					(*map)[edge].cost = std::min((*map)[edge].cost, point.cost + static_cast<long>(edge.cost));
					if ((*map)[edge].cost <= range)
					{
						if (std::find(begin(candidates), end(candidates), edge) == end(candidates))
						{
							candidates.emplace_back(SimplePoint(edge));
						}
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
		map->clear_visited();
		std::list<SimplePoint> candidates; //lista kandydatow do nastepnej iteracji algorytmu Dijkstry
		map->points[proceeded_base.y][proceeded_base.x].cost_reversed = 0; //ustawienie punktu startowego(bazy)
		map->points[proceeded_base.y][proceeded_base.x].visited = true;
		candidates.emplace_front(proceeded_base.x, proceeded_base.y);
		while (!candidates.empty())
		{
			SimplePoint proceeded_point = candidates.front(); //procedowanie na punkcie z na punkcie z najmniejszym kosztem
			candidates.pop_front();
			Point& point = map->points[proceeded_point.y][proceeded_point.x];
			point.visited = true;
			for (auto& edge : point.edges_reversed)
			{ //ustawienie na górnego ograniczenia kosztu na dostêpnych punktach
				if (!(*map)[edge].visited)
				{
					(*map)[edge].cost_reversed = std::min((*map)[edge].cost_reversed, point.cost_reversed + static_cast<long>(edge.cost));
					if ((*map)[edge].cost_reversed <= range)
					{
						if (std::find(begin(candidates), end(candidates), edge) == end(candidates))
						{
							candidates.emplace_back(SimplePoint(edge));
						}
					}
				}
			}
			//przesortowanie punktów celem wy³onienia punktu z najni¿szym górnym ograniczeniem do nastêpnej iteracji
			candidates.sort(comparator);
		}
	}


	//przeliczenie dostepnych punktow
	achievable_points = 0;
	/*	for (auto & line : map->points)
		{
			for (auto & point : line)
			{
				if (range >= point.cost + point.cost_reversed)
				{
					achievable_points++;
				}
			}
		}*/
	std::list<std::pair<int, int>> result;
	for (int y = 0; y < map->points.size(); y++)
	{
		for (int x = 0; x < map->points[y].size(); x++)
		{
			if (range >= map->points[y][x].cost + map->points[y][x].cost_reversed)
			{
				achievable_points++;
				result.push_back(std::make_pair(x, y));
			}
		}
	}
	map->clear();
	map->clear_visited();

#ifdef BENCHMARKS
	System::Console::WriteLine(achievable_points);
	std::cout << "objective function: " << duration_cast<milliseconds>(high_resolution_clock::now() - t1).count() << "ms" << std::endl;
#endif BENCHMARKS
	return result;
}
