// ** Disjoint Union Set ** //

// We are using DSU to detect cycle in an undirected graph.
// We store the parents of each node and when there is an edge between 2 nodes having same parent, then
// there is a cycle present.

// Idea is to keep on joining 2 different sets.
// But if there was a connection between 2 sets pehle se and again daal re then cycle.

// We will use edge list to make DSU.

class DSU {
	vector<vector<int>> edgeList; // Assume that this is given.
	int V;

	// Methods

	// Find the top parent of the node i, recursive function
	int findSet(int i, int parent[]) {
		if (parent[i] == -1)
			return i;

		return findSet(parent[i], parent);
	}

	// Function to merge 2 sets, if there is a connection already
	// then there is a cycle.
	bool unionSet(int x, int y, int parent[]) {
		int s1 = findSet(x);
		int s2 = findSet(y);

		// If there was a connection
		if (s1 == s2) {
			return true;
		}

		// If not, then connect them
		parent[s1] = s2;
		return false;  // No cycle ab tk.
	}

	// Cycle hai ya ni, wo saare nodes ko jab union set pe daalenge tb pta chalega
	bool containsCycle() {
		int *parent = new int[V];

		// Mark all having no parent
		for (int i = 0; i < V; i++)
			parent[i] = -1;

		// Now start merging the sets (nodes)
		for (auto edge : edgeList) {
			int u = edge[0], v = edge[1];

			// Along with merging, also check for cycle
			bool isCyclePresent = unionSet(u, v, parent);
			if (isCyclePresent)
				return true;
		}

		return false;
	}

// Further we will see optimization in both the functions.
}