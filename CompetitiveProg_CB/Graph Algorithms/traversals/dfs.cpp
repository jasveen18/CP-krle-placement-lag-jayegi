// Depth First Search
// Recursive Approach
// Goes deep into all the nodes and it's neighbors
// and then return back.

template<typename T>
class Graph {
	map<T, list<T>> l;

public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited) {
		// Recusive Function to traverse the graph.

		cout << src << " ";
		visited[src] = true;

		// Go to all neighbors of that node that is not visited.
		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited);
			}
		}

		return;
	}

	void dfs(T src) {
		map<T, bool> visited;
		// Mark all the nodes as not visited.
		for (auto node_pair : l) {
			T node = node_pair.first;
			visited[node] = false;
		}

		// Call the helper (recursive function)
		dfs_helper(src, visited);
	}
};

// Define Graph like -
// Graph<int> g;