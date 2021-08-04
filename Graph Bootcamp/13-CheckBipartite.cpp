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
bool dfs(vector<vector<int>>& graph, vector<int> &state, int src, int color) {
	state[src] = color;

	for (auto nbr : graph[src]) {
		if (state[nbr] == (3 - color))
			continue;

		if (state[nbr] == color)
			return false;

		bool ans = dfs(graph, state, nbr, 3 - color);
		if (ans == false)
			return false;
	}

	return true;
}

bool isBipartite(vector<vector<int>>& graph) {
	// Given an adj list
	// For checking is graph is bipartite, we can do 2-coloring problem

	int n = graph.size();
	vector<int> state(n, 0); // 0 -> not visited, 1 -> color 1, 2 -> color 2

	for (int i = 0; i < n; i++) {
		if (state[i] == 0) {
			bool ans = dfs(graph, state, i, 1);

			if (ans == false)
				return false;
		}
	}

	for (auto st : state)
		cout << st << " ";
	cout << endl;

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