/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if a graph can be divided into bipartite graph.
// 1. 2 Sets
// 2. All the nodes will be from one node to another. There is no internal edges allowed.
// 3. 2 Coloring problem hai.

// ** DFS ** //
bool isBipartiteDFS(vector<vector<int>> &graph) {
	int V = graph.size();
	// 0 -> not visited, 1 - color1, 2 - color2
	vector<int> state(V, 0);

	bool ans = true;

	// Traverse through all nodes to check for disconnected comps
	for (int i = 0; i < n; i++) {
		if (state[i] == 0) {
			ans = ans and isBipartiteDFSHelper(graph, i, -1, 1, state);
		}
	}

	return ans;
}


bool isBipartiteDFSHelper(vector<vector<int>> &graph, int node, int parent, int color, vector<int> &state) {
	state[node] = color;

	for (auto nbr : graph[node]) {                            // Kind of complement of 1 and 2. 2 hoga toh 1 ban jayega and vice.
		bool subGraphSolve = isBipartiteDFSHelper(graph, nbr, node, (3 - color), state);

		if (subGraphSolve == false)
			return false;

		// If visited hai and color bhi same as current node
		else if (color == state[nbr])
			return false;
	}

	return true;
}


// ** BFS ** //
bool isBipartiteBFSHelper(int V, vector<int> adjList[]) {
	vector<int> state(V, 0);
	// 0 -> not visited, 1 - color1, 2 - color2

	// {vertex, color}
	queue<pair<int, int>> q;

	// Loop to also consider disconnected components
	for (int i = 0; i < V; i++) {
		if (state[i] == 0) {
			q.push({i, 1});
			state[i] = 1;

			while (!q.empty()) {
				int currNode = q.front().first;
				int currColor = q.front().second;
				q.pop();

				for (int nbr : adjList[currNode]) {
					// If any neighbor is already colored as parent
					if (state[nbr] == currColor)
						return false;

					// If uncolored
					if (state[nbr] == 0) {
						state[nbr] = (3 - currColor);
						q.push({nbr, state[nbr]});
					}
				}
			}
		}
	}

	return true;
}