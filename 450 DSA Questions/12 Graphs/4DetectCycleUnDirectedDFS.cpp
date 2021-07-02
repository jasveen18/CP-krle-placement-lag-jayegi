/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Detect Cycle in an undirected graph using DFS.
// Here we don't need to care about the path, here we want to check the parent.
// Kyunki undirected pe parent->children and parent<-childre dono hoga.

bool containsCycle(int V, vector<int> adjList[]) {
	vector<bool> visited(V, false);
	int parent = -1;

	return findCycleRecursive(0, adjList[], visited, parent);
}

// Cycle is there when visited is true and child != parent.
bool findCycleRecursive(int src, vector<int> adjList[], vector<int> &visited, int parent) {
	visited[src] = true;

	for (int nbr : adjList[src]) {
		// First case to check deeper nodes
		if (visited[nbr] == false) {
			// Find in smaller subprob
			bool cycleMila = findCycleRecursive(nbr, adjList, visited, src);
			if (cycleMila)
				return true;
		}

		else if (visited[nbr] == true and nbr != parent)
			return true;
	}

	return false;
}