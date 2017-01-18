#include "Graph.hpp"
#include <list>
#include <algorithm>
#include <functional>
#include <chrono>
#include <iostream>
#include "Dijkstra.hpp"

using namespace std::chrono;

Graph::Graph(System::Drawing::Image^ img, int max_slope)
{
	System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(img);
	int scale = 2;
	int dividend = 1;
	int cost_of_path = 5;
	std::vector<std::vector<double>> heights;
	heights.reserve(bitmap->Height / scale);
	for (int y = 0; y < bitmap->Height; y += scale) {
		std::vector<double> line;
		line.reserve(bitmap->Width / scale);
		for (int x = 0; x < bitmap->Width; x += scale) {
			double sum = 0;
			for (int xx = 0; xx < scale; xx++) {
				for (int yy = 0; yy < scale; yy++) {
					sum += bitmap->GetPixel(x + xx, y + yy).GetHue();
				}
			}
			line.push_back(static_cast<double>(sum) / (scale*scale) / dividend);
		}
		heights.emplace_back(std::move(line));
	}
	//dzikie rozniczkowanie
	for (int y = 0; y < heights.size(); y++) {
		std::vector<Point> line;
		for (int x = 0; x < heights[y].size(); x++) {
			std::vector<Edge> edges;
			std::vector<Edge> edges_reversed;
			for (int xx = (x == 0 ? 0 : -1); xx <= (x == heights[y].size() - 1 ? 0 : 1); xx++) {
				for (int yy = (y == 0 ? 0 : -1); yy <= (y == heights.size() - 1 ? 0 : 1); yy++) {
					if (!(xx == 0 && yy == 0))
					{
						double slope = heights[y][x] - heights[y + yy][x + xx];
						if (std::abs(slope) < max_slope) {
							double flat_path = (std::abs(xx) + std::abs(yy) == 2.0 ? 1.41 : 1.0)*cost_of_path;
							edges.emplace_back(Edge(x + xx, y + yy, std::max(static_cast<int>(flat_path + slope),0)));
							edges_reversed.emplace_back(Edge(x + xx, y + yy, std::max(static_cast<int>(flat_path - slope),0)));
						}
					}
				}
			}
			line.emplace_back(edges, edges_reversed);
		}
		this->points.emplace_back(std::move(line));
	}

}

void Graph::clear()
{
	for (auto & line : points)
	{
		for (auto & point : line)
		{
			point.visited = false;
			point.cost = LONG_MAX / 3;
			point.cost_reversed = LONG_MAX / 3;
		}
	}
	return;
}

void Graph::clear_visited()
{
	for (auto & line : points)
	{
		for (auto & point : line)
		{
			point.visited = false;
		}
	}
}


adj_matrix Graph::get_adjacency_matrix(std::shared_ptr<Solution> actual, long range)
{
	auto dijkstra= Dijkstra<decltype(this), decltype(actual)>::get_dijkstra(this, actual);
	this->clear();
	adj_matrix adjacency_matrix;
	for(auto& proceeded_base : actual->bases)
	{
		std::vector<bool> vect(actual->bases.size()); //wiersz w macierzy przyleglosci
		dijkstra->set_start(proceeded_base);
		while(!dijkstra->are_candidates_empty())
		{
			dijkstra->get_proceeded_point();
			auto it = actual->bases.begin();
			for (int i = 0; i < actual->bases.size(); i++, ++it) { //sprawdzenie czy punkt nie jest baz¹
				if ((it->x == dijkstra->proceeded_point.x) && (it->y == dijkstra->proceeded_point.y)) {
					vect[i] = true;
				}
			}
			dijkstra->add_candidates(range);
		}
		dijkstra->clear_all();
		adjacency_matrix.emplace_back(std::move(vect));
	}
	for(int i=0; i<adjacency_matrix.size(); i++)
	{
		adjacency_matrix[i][i] = false;
	}
	return adjacency_matrix;
}