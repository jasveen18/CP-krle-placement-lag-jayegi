// Cycle detection in an undirected graph using a DSU.
// 1. Path Compression Optimisation in DSU (Find Function)
// 2. Union by Rank (Union Function)
// After doing these 2 changes, our DSU has almost O(1) complexity.


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

		// We do a path compression here.
		// We update the parent directly to the "-1" wala node.
		return parent[i] = findSet(parent[i], parent);
	}

	// Union
	bool unionSet(int x, int y, int parent[], int rank[]) {
		int s1 = findSet(x, parent);
		int s2 = findSet(y, parent);

		// Optimisation of Union by Rank
		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] = rank[s2];
			}
			return false;
		} else {
			return true;
		}
	}


	bool containsCycle() {
		// DSU Logic to check if a graph contains cycle or not.
		int *parent = new int[V];
		int *rank = new int[V];
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for (auto edge : edgeList) {
			int i = edge.first;
			int j = edge.second;

			bool isCyclePresent = unionSet(i, j, parent, rank);
			if (isCyclePresent)
				return true;
		}

		delete [] parent;
		return false;
	}


	int pairing() {
		// Init DSU Logic
		int *parent = new int[V];
		int *rank = new int[V];

		for (int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for (auto edge : edgeList) {
			int i = edge.first;
			int j = edge.second;
			unionSet(i, j, parent, rank);
		}

		int ans = 0;
		for (int i = 0; i < V; i++) {
			ans += V - rank[findSet(i, parent)];
		}

		delete [] parent;
		delete [] rank;
		return ans;
	}
};