/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the longest path in Directed Acyclic Graph from a given src.

// Since DAG hai toh topological sorting aana chaiye mind m.
// Ek point, it is NP Hard problem to find the longest path in a normal graph.

// Approach -
// 1. Take the ordering of Topological sort.
// 2. Initialize all distances as -INF, except src, src = 0.
// 3. Topological sort ke ordering pe nodes ko process krenge, and ->
// 	  if(dist[currNode] + weigth[nbr] < dist[nbr])
// 			update dist[nbr]

void topologicalDFS(int src, vector<pair<int, int>> adjList[], vector<bool> &visited, vector<int> &stack) {
	visited[src] = true;

	for (auto nbr : adjList[src]) {
		if (visited[nbr.fist] == false) {
			topologicalDFS(nbr.first, adjList, visited);
		}
	}

	// Push into front for topological order
	stack.push_front(src);
}


void longestPath(int src, int V, vector<pair<int, int>> adjList[]) {
	vector<bool> visited(V, false);
	vector<int> stack; // to store the topological ordering


	// 1. Find the topological ordering
	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			topologicalDFS(i, adjList, visited, stack);
		}
	}


	// 2. Initialize distances as neg inf.
	vector<int> dist(V);
	for (int i = 0; i < n; i++)
		dist[i] = INT_MIN;
	dist[src] = 0; // because src -> src = 0.


	// 3. Traverse in the topological ordering
	for (int i = 0; i < n; i++) {
		int currNode = stack[i];

		for (auto nbr : adjList) {
			dist[nbr.first] = max(dist[nbr.first], dist[currNode] + nbr.second);
		}
	}

	// Return the longest path
	return dist;
}