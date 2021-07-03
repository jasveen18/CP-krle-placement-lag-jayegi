// *** Kosaraju Algorithm *** //
// To find the number of stongly connected components.

// What is a Strongly Connected Component?
// Componenet from where you can reach all the other nodes in that component.
// If you pick any node in that component, you can reach all the other nodes.

// Kosaraju Algorithm
// 1. DFS, get an ordering list on the basis upon finish time. At the end of the function, push into stack.
// 2. Reverse the graph.
// 3. Do DFS in the copy graph from right to left as in ordering list (stack pop pop).

// You can print and count both.

void dfsToStore(vector<int> adjList[], int src, vector<bool> &visited, vector<int> &stack) {
	visited[src] = true;

	for (auto nbr : adjList[src]) {
		if (visited[src] == false)
			dfsToStore(adjList, nbr, visited, stack);
	}

	// After function push into stack
	stack.push_back(src);
}


void dfsNormal(vector<int> adjList[], int src, vector<bool> &visited) {
	visited[src] = true;
	// cout << src << " ";

	for (auto nbr : adjList[src]) {
		if (visited[src] == false)
			dfsNormal(adjList, nbr, visited);
	}
}


void kosarajuAlgo(vector<int> adjList[], int V) {
	vector<bool> visited(V, false);

	// Stack to store the ordering based on finish time.
	vector<int> stack;

	// Step 1 - Store the vertices of graph according to finish time.
	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			dfsToStore(adjList, i, visited, stack);
		}
	}


	// Step 2 - Reverse the graph and store it.
	vector<int> revAdjList[] = new vector<int>[V];

	for (int i = 0; i < V; i++) {
		for (auto nbr : adjList[i]) {
			revAdjList[nbr].push_back(i);
		}
	}


	// Step 3 - Do DFS according to the ordering list
	fill(visited.begin(), visited.end(), false);
	int compCount = 0;

	for (int x = stack.size() - 1; x >= 0; x--) {
		int currNode = stack[x];

		if (visited[currNode] == false) {
			// cout<<compCount<<" -> ";
			dfsNormal(revAdjList, currNode, visited);
			compCount++;
		}
	}

	return;
}