/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the length of shorted cycle by BFS

int shortestCycle(int src, int V, vector<int> adjList[]) {
	vector<int> distance(n + 1, INT_MAX);
	queue<int> q;
	int ans = INT_MAX;

	q.push(src);
	distance[src] = 0;

	while (!q.empty()) {
		int currNode = q.front();
		q.pop();

		// Traverse the neighbors
		for (int nbr : adjList[currNode]) {
			// If node is not visited then distance add krdo and move ahead.
			if (distance[nbr] == INT_MAX) {
				q.push(nbr);
				distance[nbr] = distance[currNode] + 1;
			}

			// If already visited hai and parent se bada bhi hai
			else if (distance[nbr] >= distance[currNode]) {
				ans = min(ans, distance[nbr] + distance[currNode] + 1);
			}
		}
	}

	return ans;
}