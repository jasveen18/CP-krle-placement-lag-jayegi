// *** BellMann Ford Shortest Path / Cycle Detection *** //

// It is used when we have a negative weighted graph (negative edges).
// The issue here is to minimize the distance, we will fall into an inf cycle.
// Used to detect negative cycle / single source shortest path (can't use dijkstra as it'll end up in a inf loop)

// Approach -
// 1. Initialize all the distances as infinite
// 2. Relax all the edges, V-1 times (Bottom up DP jaise)
// 3. Detect Negative Weight Cycle to avoid negative infinite.

// T - O((V-1) * E) | S - O(V)

// We will use a edge list to implement this.
vector<int> bellmanFord(int V, int src, vector<vector<int>> edgeList) {
	// 1. Create the distance vector
	vector<int> dist(V + 1, INT_MAX);
	dist[src] = 0; // Since source -> source, toh zero hoga.

	// 2. Relax all edges (V-1) times. Why?
	// -> we may get some edge jispe inf stored ho before we changed it later with the correct value, therefore to be sure that it is done for every node.
	// what does relaxation means?
	// take the min distance, dist[u] + wt < dist[v] => dist[v] = dist[u] + wt;
	for (int i = 0; i < V - 1; i++) {
		for (auto edge : edgeList) {
			int u = edge[0], v = edge[1], wt = edge[2];

			// Check for possible overflow and relax the edge
			if (dist[u] != INT_MAX and dist[u] + wt < dist[v])
				dist[v] = dist[u] + wt;
		}
	}

	// 3. Check for negative weight cycle
	for (auto edge : edgeList) {
		int u = edge[0], v = edge[1], wt = edge[2];

		// If after running our algorithm, if the weights can still be updated.
		// then cycle present hai.
		if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
			// This means negative weight cycle present hai, and we can't find distances.
			return { -1};
		}
	}

	return dist;
}