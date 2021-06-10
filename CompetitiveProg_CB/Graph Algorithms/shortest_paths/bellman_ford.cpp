// It is used when we have negative weighted graphs.
// Used to find single source shortest path.

// 1. Initialize all the distances as infinite.
// 2. Relax all the edges, V-1 time, (bottom up Dp jaisa)
// 3. Detect Negative Weight Cycle to avoid negative infinite.

// We will use an edge list representation.
#include<iostream>
#include<vector>
using namespace std;

vector<int> bellman_ford(int V, int src, vector<vector<int>> edges) {
	// 1. Create the distance vector
	vector<int> dist(n + 1, INT_MAX);
	dist[src] = 0;

	// 2. Relax all edges V-1 times.
	for (int i = 0; i < V - 1; i++) {
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			// Check for possible overflow and then relax the edge
			if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}

	// 3. Check for negative weight cycle
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];

		// If after running our algorithm, the weights are still updates
		if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
			cout << "Negative Weigth Cycle Present";
			exit(0);
		}
	}


	return dist;
}


int main() {
	// Number of vertices and edges.
	int n, m; cin >> n >> m;

	// Edge List - (u, v, wt)
	vector<vector<int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;

		edges.push_back({u, v, wt});
	}

	// Bellman Ford Algorithm
	vector<int> distances = bellman_ford(n, 1, edges);

	for (int i = 1; i <= n; i++) {
		cout << "Node " << i << " is at distance " << distance[i] << endl;
	}
}