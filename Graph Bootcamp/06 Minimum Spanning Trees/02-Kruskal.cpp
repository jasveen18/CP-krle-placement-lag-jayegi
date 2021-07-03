// ** Kruskal Algorithm ** //


// Approach -
// 1. Sort the edges in the order of non-decreasing weight
// 2. Pick the edges which will not form a cycle.
// 3. Keep on doing this till we have processed all the edges.

// We will use DSU here to detect the cycle between edges.

int kruskalMST(int V, vector<vector<int>> edgeList) {
	// Edgelist
	// 0 -> u, 1 -> v, 2 -> weight;

	// Sort the edges on the basis of weight
	sort(edgeList.begin(), edgeList.end(), [](vector<int> &a, vector<int> &b) {
		return a[2] < b[2];
	});

	// Initialize a DSU.  // Assume we have a class DSU with all the DSU methods.
	DSU s(V);

	int ans = 0;
	// u, v, weight
	vector<pair<pair<int, int>, int>> edgesIncluded;

	for (auto edge : edgeList) {
		int u = edge[0], v = edge[1], wt = edge[2];

		// If there is no cycle formation for this edge.
		if (s.findSet(u) != s.findSet(y)) {
			s.unionSet(u, v);

			// Add weight to the answer
			ans += wt;
			edgesIncluded.push_back({{u, v}, wt});
		}
	}

	// return edgesIncluded;
	return ans;
}