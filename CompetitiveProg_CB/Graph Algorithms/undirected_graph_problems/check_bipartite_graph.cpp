// Bipartite Graph?
// ----------------
// - You can divide all verice of graph in 2 sets
// - such that all edges of the graph are from set1 to set2
// - also known as two coloring problem

#include<iostream>
#include<vector>
using namespace std;


bool dfs_check(vector<vector<int>> &graph, int node, int parent, int color, vector<int> &visited) {

	visited[node] = color;

	for (auto nbr : graph[node]) {
		// If not visited, then visit
		if (visited[nbr] == 0) {
			bool subGraph = dfs_check(graph, nbr, node, (3 - color), visited);
			if (!subGraph)
				return false;
		}
		// if visited hai and color bhi same hai.
		else if (color == visited[nbr])
			return false;
	}

	return true;
}


bool isBipartite(vector<vector<int>>& graph) {
	int n = graph.size();
	// 0 - not visited, 1 - color1, 2 - color2.
	vector<int> visited(n);

	bool ans = true;

	// Check for disconnected graphs too.
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			ans = ans and dfs_check(graph, i, -1, 1, visited);
		}
	}

	return ans;
}


int main() {
	int N, M;
	cin >> N >> M;

	// Adjacency List
	vector<vector<int>> graph;

	while (M--) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}


	// BFS or DFS, by coloring the nodes at each step
	// (if current node has color1, neighbor should have color2)
	cout << isBipartite(graph);
}