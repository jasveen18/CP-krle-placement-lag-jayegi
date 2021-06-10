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

	void dfs() {
		map<T, bool> visited;
		// Mark all the nodes as not visited.
		for (auto node_pair : l) {
			T node = node_pair.first;
			visited[node] = false;
		}

		// Call the helper (recursive function)

		// Iterate over all the vertices and itiate
		// a dfs call if not visited.

		int cnt = 0;
		for (auto node_pair : l) {
			T node = node_pair.first;
			if (!visited[node]) {
				cout << "Component: " << cnt << "-> ";
				dfs_helper(node, visited);
				cout << endl;
				cnt++;
			}
		}
	}
};