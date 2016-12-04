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
			point.cost = LONG_MAX;
			point.cost_reversed = LONG_MAX;
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

adj_matrix Graph::get_adjacency_matrix(Solution& actual, long range)
{
	//struktura, ktora posiada w sobie wspolrzedne - upraszcza i przyspiesza generowanie listy kandydatow do nastepnej iteracji
	struct SimplePoint{
		SimplePoint(int x, int y) : x(x), y(y) {}
		SimplePoint(Edge edge):x(edge.x),y(edge.y) {}
		int x;
		int y;
		bool operator==(const SimplePoint& rhs) const { return (this->x == rhs.x) && (this->y == rhs.y); }
	};
	//funkcja, ktora jest uzywana pozniej do sortowania listy kandydatow
	auto comparator = [this](const SimplePoint& b1, const SimplePoint& b2)->bool{
		return ((this->points[b1.y][b1.x].cost) < (this->points[b2.y][b2.x].cost));
	};
	//macierz przyleglosci
	adj_matrix adjacency_matrix;
	//przeiterowanie po wszystkich bazach
	for (auto& proceeded_base : actual.bases)
	{
		std::vector<bool> vect(actual.bases.size()); //wiersz w macierzy przyleglosci
		std::list<SimplePoint> candidates; //lista kandydatow do nastepnej iteracji algorytmu Dijkstry
		this->points[proceeded_base.y][proceeded_base.x].cost = 0; //ustawienie punktu startowego(bazy)
		this->points[proceeded_base.y][proceeded_base.x].visited = true;
		candidates.emplace_front(proceeded_base.x, proceeded_base.y);
		while (!candidates.empty()) {
			SimplePoint proceeded_point = candidates.front(); //procedowanie na punkcie z na punkcie z najmniejszym kosztem
			candidates.pop_front();
			auto it = begin(actual.bases);
			for (int i = 0; i < actual.bases.size(); i++, ++it) { //sprawdzenie czy punkt nie jest baz¹
				if ((it->x == proceeded_point.x) && (it->y == proceeded_point.y)) {
					vect[i] = true;
				}
			}
			candidates.pop_front();
			Point& point = this->points[proceeded_point.y][proceeded_point.x];
			point.visited = true;
			for (auto& edge : point.edges) { //ustawienie na górnego ograniczenia kosztu na dostêpnych punktach
				if (!(*this)[edge].visited) {
					(*this)[edge].cost = std::min((*this)[edge].cost, point.cost + static_cast<long>(edge.cost));
					if ((*this)[edge].cost <= range) {
						if (std::find(begin(candidates), end(candidates), edge) == end(candidates))
							candidates.emplace_back(SimplePoint(edge));
					}
				}
			}
			//przesortowanie punktów celem wy³onienia punktu z najni¿szym górnym ograniczeniem do nastêpnej iteracji
			candidates.sort(comparator);
		}
		this->clear();
		adjacency_matrix.emplace_back(std::move(vect));
		for (int i = 0; i < adjacency_matrix.size(); i++) { //zabronienie drogi do samego siebie(ustawia siê automatycznie w pierwszej iteracji)
			adjacency_matrix[i][i] = false;
		}
	}
	return adjacency_matrix;
}