// Cycle detection in an undirected graph using a DSU.

class Graph {
	// Edge between u and v. This is edge list.
	list<pair<int, int>> edgeList;
	int V;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int u, int v) {
		edgeList.push_back({u, v});
	}

	// DSU Functions
	// Find
	int findSet(int i, int parent[]) {
		if (parent[i] == -1) {
			return i;
		}

		return findSet(parent[i], parent);
	}

	// Union
	bool unionSet(int x, int y, int parent[]) {
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		if (s1 != s2) {
			parent[s1] = s2;
			return false;
		} else {
			return true;
		}
	}


	bool containsCycle() {
		// DSU Logic to check if a graph contains cycle or not.
		int *parent = new int[V];
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
		}

		for (auto edge : edgeList) {
			int i = edge.first;
			int j = edge.second;

			bool isCyclePresent = unionSet(i, j, parent);
			if (isCyclePresent)
				return true;
		}

		delete [] parent;
		return false;
	}
};