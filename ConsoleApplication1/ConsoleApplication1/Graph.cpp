#include "Graph.hpp"
#include <list>
#include <algorithm>
#include <functional>

Graph::Graph()
{

}

Graph::Graph(System::Drawing::Image^ img)
{
	System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(img);
	int scale = 2;
	int dividend = 20;
	int cost_of_path = 10;
	std::vector<std::vector<double>> heights;
	for (int y = 0; y < bitmap->Height; y += scale) {
		std::vector<double> line;
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
	for(int y=0; y<heights.size(); y++){
		std::vector<Point> line;
		for (int x = 0; x < heights[y].size(); x++) {
			std::vector<Edge> edges;
			std::vector<Edge> edges_reversed;
			for (int xx=(x==0 ? 0 : -1); xx <= (x==heights[y].size()-1 ? 0 : 1); xx++) {
				for (int yy = (y==0 ? 0 : -1); yy <= (y==heights.size()-1 ? 0 : 1); yy++) {
					if (!(xx == 0 && y == 0))
					{
						edges.emplace_back(x+xx, y+yy, static_cast<int>(std::abs((std::abs(xx)+std::abs(yy)==2 ? 1.41 : 1)*(heights[y+yy][x+xx]-heights[y][x]+cost_of_path))));
						edges_reversed.emplace_back(x + xx, y++, static_cast<int>(std::abs((std::abs(xx), std::abs(yy) == 2 ? 1.41 : 1)*(heights[y][x] - heights[y + yy][x + xx] + cost_of_path))));
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
		}
	}
	return;
}

adj_matrix Graph::get_adjacency_matrix(Solution& actual, int range)
{
	struct SimplePoint{
		SimplePoint(int x, int y) : x(x), y(y) {}
		SimplePoint(Edge edge):x(edge.x),y(edge.y) {}
		int x;
		int y;
		bool operator==(const SimplePoint& rhs) const { return (this->x == rhs.x) && (this->y == rhs.y); }
	};
	std::function<bool(const SimplePoint&,const SimplePoint&)> comparator = [this](const SimplePoint& b1, const SimplePoint& b2)->bool{
		return ((this->points[b1.y][b1.x].cost) < (this->points[b2.y][b2.x].cost));
	};

	adj_matrix adjacency_matrix;
	for (auto& proceeding_base : actual.bases)
	{
		std::vector<bool> vect(actual.bases.size());
		std::list<SimplePoint> candidates;
		this->points[proceeding_base.y][proceeding_base.x].cost = 0;
		candidates.emplace_front(proceeding_base.x, proceeding_base.y);
		while (this->points[begin(candidates)->y][begin(candidates)->x].cost <= range) {
			SimplePoint proceeded_point = candidates.front();
			auto it = begin(actual.bases);
			for (int i = 0; i < actual.bases.size(); i++, ++it) {
				if ((it->x == proceeded_point.x) && (it->y == proceeded_point.y)) {
					vect[i] = true;
				}
			}
			candidates.pop_front();
			Point& point = this->points[proceeded_point.y][proceeded_point.x];
			for (auto& edge : point.edges) {
				(*this)[edge].cost = std::min((*this)[edge].cost, point.cost+static_cast<long>(edge.cost));
				if (std::find(begin(candidates), end(candidates), edge) == end(candidates))
					candidates.emplace_back(edge);
			}
			candidates.sort(comparator);
		}
		this->clear();
		adjacency_matrix.emplace_back(std::move(vect));
		for (int i = 0; i < adjacency_matrix.size(); i++) {
			adjacency_matrix[i][i] = false;
		}
	}
	return adjacency_matrix;
}