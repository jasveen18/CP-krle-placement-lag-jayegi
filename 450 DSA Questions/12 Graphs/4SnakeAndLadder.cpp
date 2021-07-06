/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find min way to reach (N,N) from (N, 0), diagonal traversal. With snakes and ladders.

// We will use BFS shortest path.
int minDiceThrows(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders) {
	vector<int> board(n + 1, 0);

	// Board to graph
	for (auto sp : snakes) {
		int s = sp.first;
		int e = sp.second;

		board[s] = e - s;
	}

	for (auto lp : ladders) {
		int s = lp.first;
		int e = lp.second;

		board[s] = e - s;
	}

	// Graph
	vector<int> adjList[n];

	for (int u = 1; u < n; u++) {
		for (int dice = 1; dice <= 6; dice ++) {
			int destination = u + dice;
			// Add if any ladder or snake is present
			destination += board[destination];

			if (destination <= n)
				adjList[u].push_back(destination);
		}
	}

	int src = 1, dest = n;
	cout << minCostBFS(adjList, src, dest, n);
}


int minCostBFS(vector<int> adjList[], int src, int dest, int n) {
	queue<int> q;
	vector<bool> visited(n, false);
	vector<int> dist(n, 0);

	q.push(src);
	visited[src] = true;
	dist[src] = 0;

	while (!q.empty()) {
		int curr = q.top(); q.pop();

		for (auto nbr : adjList[curr]) {
			if (visited[nbr] == false) {
				q.push(nbr);
				visited[nbr] = true;
				dist[nbr] = 1 + dist[curr];
			}
		}
	}

	return dist[dest];
}