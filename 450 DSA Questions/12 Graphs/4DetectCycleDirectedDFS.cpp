/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Detect Cycle in a directed graph using DFS

bool containsCycle(int V, vector<int> adjList[]) {
	vector<bool> visited(V, false);
	vector<bool> path(V, false);

	return findCycleRecursive(0, adjList, visited, path);
}


bool findCycleRecursive(int src, vector<int> adjList[], vector<int> &visited, vector<int> &path) {
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