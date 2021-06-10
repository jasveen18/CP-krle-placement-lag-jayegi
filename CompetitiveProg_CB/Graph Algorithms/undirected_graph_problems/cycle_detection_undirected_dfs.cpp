class Graph {
	int V;
	list<int> *l;
public:
	Graph(int V) {
		this->V = V;
		l = new list<int> [V];
	}
	void addEdge(int x, int y, bool directed = true) {
		l[x].push_back(y);

		if (!directed) {
			l[y].push_back(x);
		}
	}

	bool cycle_helper(int node, bool *visited, int parent) {
		visited[node] = true;

		for (auto nbr : l[node]) {
			if (!visited[nbr]) {
				// Go and visit the neighbor
				bool cycle_mila = cycle_helper(nbr, visited, node);
				if (cycle_mila)
					return true;
			}
			// nbr is visited but not be equal to parent
			else if (nbr != parent) {
				return true;
			}
		}

		return false;
	}

	bool contains_cycle() {
		bool *visited = new bool[V];
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}

		return cycle_helper(0, visited, -1);
	}
}