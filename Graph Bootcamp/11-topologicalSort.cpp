// ** Topological Sort ** //
// Real world problem
// It is used in dependency.
// You need to sort and know which steps to follow so that
// there are no clashes of dependencies.

// Supppose you want to build Face Recognition
// You need to learn python, data preprocessing, data visualization,
// ML basics, Pytorch, DL, ML, Face Recog algo.
// Here for data preprocessing, and visualization, python is depedence.
// For Ml, python hai; for DL, ML hai; for DL, pytorch hai; for pytorch, python hai.

// Only applicable on directed acyclic graph.

// *** DFS *** //
// 1. DFS traversal kro and then when the traversal is done, put the current element into the start of the ordering.
// 2. List use krlo to have O(1) insertion at start.
// 3. Idea is ki DFS goes into deep toh when wapis aayega toh non-dependancy wala top pe hoga.

vector<int> topologicalSortDFS(int v, vector<int> adjList[]) {
	vector<bool> visited(v, false);
	list<int> sortedList;

	// Run DFS for all the nodes to cover the components
	for (int i = 0; i < v; i++) {
		if (visited[i] == false) {
			topoSortRecursive(i, visited, adjList);
		}
	}

	// Return the output
	vector<int> res;
	for (auto el : sortedList)
		res.push_back(el);

	return res;
}


void topoSortRecursive(int src, vector<bool> &visited, vector<int> adjList[]) {
	visited[src] = true;

	for (auto nbr : adjList[src]) {
		if (visited[nbr] == false) {
			topoSortRecursive(nbr, visited, adjList);
		}
	}

	// After this, we can add this node to the start of sorted list.
	sortedList.push_front(src);
}


// *** BFS *** //
// 1. The idea here is to maintain a indegree for all the nodes.
// 2. When the indegree is zero, we print the node.
vector<int> topologicalSortBFS(int v, vector<int> adjList[]) {
	vector<int> inDegree(v, 0);
	vector<int> res;

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
		res.push_back(curr);

		// For all it's neighbors we will decrease the indegree as this node is processed.
		// If the indegree == 0, we push into queue.
		for (int nbr : adjList[curr]) {
			inDegree[nbr]--;

			if (inDegree[nbr] == 0)
				q.push(nbr);
		}
	}

	return res;
}