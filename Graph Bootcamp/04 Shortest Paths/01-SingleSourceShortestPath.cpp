/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - For an unweighted graph, find the shortest path from one node to another.
// We will find the shortest path from src to all other nodes.

void printShortestPath(int src, int V, vector<int> adjList[]) {
	map<int, int> dist;
	queue<int> q;

	// All nodes will initially have INT_MAX dist (not visited)
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;

	// Source se start krte hai uska distance toh zero hoga khud se
	q.push(src);
	dist[src] = 0;

	// BFS
	while (!q.empty()) {
		int currNode = q.front();
		q.pop();

		// Traverse the nodes and update distances
		for (auto nbr : adjList[currNode]) {
			// If not visited
			if (dist[nbr] == INT_MAX) {
				q.push(nbr);
				dist[nbr] = dist[currNode] + 1; // Parent se +1 will be shortest, BFS shortest deta hai.
			}
		}
	}

	// Print the distances
	for (auto el : dist) {
		cout << el.first << " " << el.second << endl;
	}

}