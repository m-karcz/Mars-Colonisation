#pragma once

#include <algorithm>
#include "Base.hpp"
#include "Edge.hpp"
#include <memory>
#include <list>


enum class Direction
{
	forward,
	backward
};

struct SimplePoint
{
	SimplePoint() = delete;
	SimplePoint(int x, int y) : x(x), y(y) {}
	SimplePoint(Edge edge) :x(edge.x), y(edge.y) {}
	SimplePoint(Base base) :x(base.x), y(base.y) {}
	operator Edge() const
	{
		return Edge(this->x, this->y, -1);
	}
	int x;
	int y;
	bool operator==(const SimplePoint& rhs) const noexcept { return (this->x == rhs.x) && (this->y == rhs.y); }
};

template<typename map_type, typename solution_type>
class Dijkstra
{
public:
	Dijkstra() = delete;
	Dijkstra(const Dijkstra&) = delete;
	void set_start();
	static std::unique_ptr<Dijkstra<map_type, solution_type>> get_dijkstra(map_type map, solution_type solution)
	{
		return std::make_unique<Dijkstra<map_type, solution_type>>(map, solution);
	}
	void set_start(SimplePoint start);
	void clear_visited();
	void clear_all();
	std::list<SimplePoint> candidates;
	SimplePoint get_proceeded_point();
	solution_type solution;
	map_type map;
	void add_candidates(long max_range);
	void set_direction(Direction dir);
	SimplePoint proceeded_point=SimplePoint(-1,-1);
	bool are_candidates_empty();
	Dijkstra(map_type map, solution_type solution) : map(map), solution(solution) {}
	Direction direction = Direction::forward;
};



template<typename map_type, typename solution_type>
void Dijkstra<map_type, solution_type>::set_start()
{
	for (auto& base : solution->bases)
	{
		this->set_start(base);
	}
}



template<typename map_type, typename solution_type>
void Dijkstra<map_type, solution_type>::set_start(SimplePoint start)
{
	Point& p = (*map)[static_cast<Edge>(start)];
	if (direction == Direction::forward)
	{
		p.cost = 0;
	}
	else
	{
		p.cost_reversed = 0;
	}
	p.visited = true;
	candidates.push_back(start);
	proceeded_point = start;
}


template<typename map_type, typename solution_type>
void Dijkstra<map_type, solution_type>::clear_visited()
{
	map->clear_visited();
}

template<typename map_type, typename solution_type>
void Dijkstra<map_type, solution_type>::clear_all()
{
	map->clear();
	map->clear_visited();
	candidates.clear();
}


template<typename map_type, typename solution_type>
SimplePoint Dijkstra<map_type, solution_type>::get_proceeded_point()
{
	auto comparator = [this](const SimplePoint& b1, const SimplePoint& b2)->bool {
		return ((this->map->points[b1.y][b1.x].cost) < (this->map->points[b2.y][b2.x].cost));
	};
	auto it_to_the_lowest = std::min_element(candidates.begin(), candidates.end(), comparator);
	proceeded_point = *it_to_the_lowest;
	candidates.erase(it_to_the_lowest);
	(*map)[proceeded_point].visited = true;
	return proceeded_point;
}


template<typename map_type, typename solution_type>
void Dijkstra<map_type, solution_type>::add_candidates(long max_range)
{
	auto& point = (*map)[proceeded_point];
	for (auto& edge : direction == Direction::forward ? point.edges : point.edges_reversed)
	{
		auto& candidate = (*map)[edge];
		candidate.cost = std::min(candidate.cost, point.cost + edge.cost);
		if (!candidate.visited && candidate.cost <= max_range)
			if (std::find(candidates.begin(), candidates.end(), edge) == candidates.end())
				candidates.push_back(edge);
	}
}

template<typename map_type, typename solution_type>
void Dijkstra<map_type, solution_type>::set_direction(Direction dir)
{
	direction = dir;
}

template<typename map_type, typename solution_type>
bool Dijkstra<map_type, solution_type>::are_candidates_empty()
{
	return candidates.empty();
}

