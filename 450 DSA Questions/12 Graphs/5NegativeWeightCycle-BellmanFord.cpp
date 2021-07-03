/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Detect if there is a negative weight cycle.
int isNegativeWeightCycle(int n, vector<vector<int>>edgeList) {
	// 1. Create the distance vector
	vector<int> dist(n + 1, INT_MAX);
	dist[0] = 0; // Since source -> source, toh zero hoga.

	// 2. Relax all edges (V-1) times. Why?
	for (int i = 0; i < n - 1; i++) {
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

		// If after running our algorithm, the weights can still be updated.
		// then cycle present hai.
		if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
			// This means negative weight cycle present hai, and we can't find distances.
			return true;
		}
	}

	return false;
}