// Floyd Warshall Algorithm
// ----------------------------------
// All pair shortest path
// Shortest between all pair of vertices
// Works with negative edges
// Can detect negative cycles, too, with one extra step

// DP based algorithm. O(V^3)
// We will use a adjacency matrix.

// 1. Make the adjacency matrix.
// 2. Iterating over all the vertices, try to make a route from
// 	  each of them.
// 3. Update the distances in adj matrix only.

#include<iostream>
#include<vector>
using namespace std;

#define INF 100000

vector<vector<int>> floyd_warshall(vector<vector<int>> graph) {
	vector<vector<int>> dist(graph);
	int V = graph.size();

	// Phases in kth phase, we include vertices(1, 2,... k) as intermediate vertices
	for (int k = 0; k < V; k++) {
		// Iterate over the entier 2D Adj Matrix
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				// If vertex k is included, and can we minimise it?
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return dist;
}


int main() {
	// Graph represented as Adj Matrix
	vector<vector<int>> graph = {
		{0, INF, -2, INF},
		{4, 0, 3, INF},
		{INF, INF, 0, 2},
		{INF, -1, INF, 0}
	};

	vector<vector<int>> shortest_distances = floyd_warshall(graph);
	for (int i = 0; i < shortest_distances.size(); i++) {
		for (int j = 0; j < shortest_distances.size(); j++) {
			cout << shortest_distances[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}