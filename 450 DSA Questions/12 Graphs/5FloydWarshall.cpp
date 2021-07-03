/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the min distance from each pair to all others.
void shortest_distance(vector<vector<int>>&dist) {
	int V = dist.size();

	// Phases in kth phase, we include vertices(1, 2,... k) as intermediate vertices
	for (int k = 0; k < V; k++) {
		// Iterate over the entier 2D Adj Matrix
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (dist[i][k] == -1 or dist[k][j] == -1)
					continue;

				if (dist[i][j] == -1)
					dist[i][j] = dist[i][k] + dist[k][j];


				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}