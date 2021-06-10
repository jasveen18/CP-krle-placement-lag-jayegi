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

	bool cycle_helper(int node, bool *visited, bool *path) {
		visited[node] = true;
		path[node] = true;

		for (int nbr : l[node]) {
			// Two cases -
			// if we find something already in existing path
			if (path[nbr] == true) {
				return true;
			}
			// Else go on to find cycle in neighbors.
			else if (visited[nbr] == false) {
				bool cycle_mila = cycle_helper(nbr, visited, path);
				if (cycle_mila)
					return true;
			}
		}

		// Leave a node
		path[node] = false;
		return _;
	}

	bool contains_cycle() {
		bool *visited = new bool[V];
		bool *path = new bool[V];

		for (int i = 0; i < V; i++) {
			visited[i] = false;
			path[i] = false;
		}

		return cycle_helper(0, visited, path);
	}
}