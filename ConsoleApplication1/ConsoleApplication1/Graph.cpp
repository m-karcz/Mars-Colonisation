#include "Graph.hpp"


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

adj_matrix Graph::get_adjacency_matrix(Solution& actual)
{
	adj_matrix todo;
	return todo;
}