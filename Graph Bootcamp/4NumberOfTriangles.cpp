/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Count the number of triangles in a directed graph.

// Adj Matrix use krenge,
// Three nested loops.
// i->j, j->k, k->i true hone pe count ++.
// But, to remove the duplicates, we will divide by 3 for directed graph.
// and by 6 for undirected graph.

int countTriangle(vector<vector<int>> &graph, bool isDirected) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (graph[i][j] and graph[j][k] and graph[k][i])
					count++;
			}
		}
	}

	if (isDirected)
		return count / 3;
	else
		return count / 6;
}