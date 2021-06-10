// What is Strongly Connected Graph
// It is a component from where,
// if you pick any single node, you can reach all other nodes in that component.

// Kosaraju Algorithm
// 1. DFS, get an ordering list based upon finish time. Last m stack pe push kr do.
// 2. Reverse the graph. (reverse the edges).
// 3. Do DFS in the copy graph from right to left as given in ordering list.



void dfs(vector<int> graph[], int i, bool *visited, vector<int> &stack) {
	visited[i] = true;

	for (auto nbr : graph[i]) {
		if (!visited[nbr]) {
			dfs(graph, nbr, visited, stack);
		}
	}

	// Function call is complete, then push into stack.
	stack.push_back(i)j;
}


void simple_dfs(vector<int> graph[], int i, bool *visited) {
	visited[i] = true;
	cout << i << " ";
	for (auto nbr : graph[i]) {
		if (!visited[nbr]) {
			simple_dfs(graph, nbr, visited);
		}
	}
}


void find_scc(vector<int> graph[], vector<int> revGraph[], int N) {
	bool visited[N];
	memset(visited, 0, N);

	// Stack to store the ordering based on finish time.
	vector<int> stack;

	// Step 1 - Store the vertices according to dfs finish time.
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(graph, i, visited, stack);
		}
	}


	// Step 2 - Reverse the graph, already done.

	// Step 3 - Do dfs according to the ordering list.
	memset(visited, 0, N);
	char compName = 'A';
	for (int x = stack.size() - 1; x >= 0; x--) {
		int node = stack[x];
		if (!visited[node]) {
			cout << compName << "-> ";
			// If not visited then there is a component starting from here.
			simple_dfs(revGraph, node, visited);
			cout << endl;
			compName++;
		}
	}

}


int main() {
	int N; cin >> N;
	vector<int> graph[N];
	vector<int> revGraph[N];


	int m; cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		revGraph[y].push_back(x);
	}

	find_scc(graph, revGraph, N);
}