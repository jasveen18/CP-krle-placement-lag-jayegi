// *** Floyd Warshall Algorithm *** //

// All pair shortest path
// This means that we will find the shortest path between all the pairs of vertices.
// Also works with negative edges.
// Can detect negative cycles, too, with just one extra step.

// OP Hai kya?

// DP Based Algorithm
// T - O(V^3) | S - O(1) or O(V^2)
// We will use adj matrix

// Approach -
// 1. Make the adjacency matrix
// 2. Iterating over all the vertices, try to make a route from each of them.
// 3. Update the distance in adj matrix.

vector<vector<int>> floydWarshall(vector<vector<int>> &graph) {
	int V = graph.size();

	// Build up the dp
	for (int k = 0; k < V; k++) {

		// Iterate over entire graph
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				// If not connected then continue as koi kaam ni hai
				if (graph[i][k] == -1 or graph[k][j] == -1)
					continue;

				// If not seen yet, then update
				if (graph[i][j] == -1)
					graph[i][j] = graph[i][k] + graph[k][j];


				// Take the minimum weighted route
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	return graph;
}