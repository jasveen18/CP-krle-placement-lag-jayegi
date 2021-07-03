/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find if it is possible to finish all tasks given some dependencies.
// Let's take the dependencies as adj list only.

// Approach 1 -
// DFS Cycle Detection
bool isCycleDFSRecursive(int src, vector<int> adjList[], vector<bool> &visited, vector<bool> &path) {
	visited[src] = true;
	path[src] = true;

	// Traverse through all it's neighbors
	for (int nbr : adjList[src]) {
		// Two cases here -
		// If we find this node already in our path, that means ki cycle hai.
		if (path[nbr] == true)
			return true;

		// Else find into smaller sub prob (neighbors ko)
		if (visited[nbr] == false) {
			bool cycleMila = findCycleRecursive(nbr, adjList, visited, path);
			if (cycleMila)
				return true;
		}
	}


	// We were not able to find cycle from here, toh path se pop kr do
	path[src] = false;
	return false;
}


bool isPossibleToCompleteJobsDFS(int V, vector<int> adjList[]) {
	// 2 arrays, one for path array and one for visited array.
	vector<bool> visited(V, false);
	vector<bool> path(V, false);

	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			bool cycleMila = findCycleRecursive(i, adjList, visited, path);
			if (cycleMila)
				return true;
		}
	}

	return false;
}


// Approach 2  -
// BFS Topological Sort
vector<int> topologicalSortBFS(int v, vector<int> adjList[]) {
	vector<int> inDegree(v, 0);
	vector<int> res;
	vector<bool> visited(v, false);

	// Update the indegree for each nodes
	for (int i = 0; i < v; i++) {
		for (int nbr : adjList[i]) {
			inDegree[nbr]++;
		}
	}

	// 1. Find the nodes with zero indegrees to start the traversal
	queue<int> q;
	for (int i = 0; i < v; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int curr = q.front(); q.pop();
		visited[curr] = true;

		// For all it's neighbors we will decrease the indegree as this node is processed.
		// If the indegree == 0, we push into queue.
		for (int nbr : adjList[curr]) {
			inDegree[nbr]--;

			if (inDegree[nbr] == 0)
				q.push(nbr);
		}
	}

	// Now check if any node was not visited.
	for (int i = 0; i < v; i++)
		if (visited[i] == false)
			return false;

	return true;
}