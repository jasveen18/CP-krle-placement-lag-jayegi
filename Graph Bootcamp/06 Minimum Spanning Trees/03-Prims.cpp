// ** Prim's Algorithm ** //

// Approach -
// BFS Algorithm
// 1. Start from any source vertex
// 2. Out of all the active edges, pick the one with smallest edge(priority queue dega ye)
//    - Now, u->v ka edge ko lie honge toh now select v.
//    - and put all active edges of v into the queue.

// Terms ->
// MST Set = {sets picked till now}
// Active Edge - Any edge available to pick
// MST Edge = [] // An edge already in MSt.

struct lowestWeight {
	bool operator()(const pair<int, int>&a, pair<int, int>&b) {
		return a.second < b.second;
	}
}

int primsMST(int V, vector<pair<int, int>> adjList[]) {
	// Priority queue with smallest weight first
	priority_queue<pair<int, int>, vector<pair<int, int>>, lowestWeight> pq;

	// Visited array to know if the node is already in MST or not
	vector<bool> visited(V, false);
	int ans = 0;
	// vector<pair<pair<int, int>, int>> edgesIncluded;

	pq.push({0, 0});
	while (!pq.empty()) {
		pair<int, int> bestEdge = pq.top();
		pq.pop();

		int currNode = bestEdge.first;
		int weight = bestEdge.second;

		// If this node is already visited, don't include this edge.
		if (visited[currNode] == true)
			continue;

		// Take this edge
		ans += weight;
		visited[currNode] = true;

		// Neighbors ko daal do
		for (auto nbr : adjList[currNode]) {
			if (visited[nbr.first] == false) {
				q.push({nbr.first, nbr.second});
			}
		}
	}

	return ans;
}