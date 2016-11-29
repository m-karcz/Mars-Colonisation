#pragma once

#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include<stack>
#include <list>
#include <algorithm>

typedef std::vector<std::vector<bool>> adj_matrix;

//inspiracja: http://eduinf.waw.pl/inf/alg/001_search/0129a.php


struct Validator
{
	static bool is_allowed(adj_matrix & matrix)
	{
		std::vector<int> C(matrix.size());
		int cn = 0;
		for (unsigned int v = 0; v < matrix.size(); v++) {
			if (C[v] > 0) {
				continue;
			}
			cn++;
			DFSccc(v, matrix, cn, C);
		}
		return std::all_of(std::begin(C), std::end(C), [](int n) {return n == 1;});
	}
private:
	static void DFSccc(int v, adj_matrix& graph, int cn, std::vector<int>& C) {
		std::vector<bool> visited(graph.size());
		std::stack<int> S;
		S.push(v);
		visited[v] = true;
		C[v] = cn;
		int u;
		while (!S.empty()) {
			u = S.top();
			S.pop();
			if (u != v && DFSback(u, v, graph)) {
				C[u] = cn;
			}
			for (unsigned int w = 0; w < graph.size(); w++) {
				if (graph[u][w]) {
					if (visited[w]) {
						continue;
					}
					S.push(w);
					visited[w] = true;
				}
			}
		}
	}
	static bool DFSback(int u, int v, adj_matrix& graph) {
		std::vector<bool> visited(graph.size());
		std::stack<int> S;
		S.push(u);
		visited[u] = true;
		int x;
		while (!S.empty()) {
			x = S.top();
			S.pop();
			for (unsigned int y = 0; y < graph.size(); y++) {
				if (graph[x][y]) {
					if (y == v) {
						return true;
					}
					if (visited[y]) {
						continue;
					}
					S.push(y);
					visited[y] = true;
				}
			}
		}
		return false;
	}
};
