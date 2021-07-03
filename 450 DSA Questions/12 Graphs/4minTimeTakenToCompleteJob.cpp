/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min Time taken to complete the job
vector<int> minTimeTakenForJob(int v, vector<int> adjList[]) {
	vector<int> inDegree(v, 0);
	vector<int> res(v, 0);

	// Update the indegree for each nodes
	for (int i = 0; i < v; i++) {
		for (int nbr : adjList[i]) {
			inDegree[nbr]++;
		}
	}

	// 1. Find the nodes with zero indegrees to start the traversal
	queue<pair<int, int>> q;
	for (int i = 0; i < v; i++) {
		if (inDegree[i] == 0)
			q.push({i, 0});
	}

	while (!q.empty()) {
		int curr = q.front().first;
		int timeTaken = q.front().second;
		q.pop();
		res[curr] = timeTaken;

		// For all it's neighbors we will decrease the indegree as this node is processed.
		// If the indegree == 0, we push into queue.
		for (int nbr : adjList[curr]) {
			inDegree[nbr]--;

			if (inDegree[nbr] == 0)
				q.push({nbr, timeTaken + 1});
		}
	}

	return res;
}