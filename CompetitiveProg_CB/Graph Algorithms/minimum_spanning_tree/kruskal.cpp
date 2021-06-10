// What is a spanning tree?
// It is a connected(all vertices are connected) weighted graph, (V-1) edges. No cycle.
// Subset of original edges.

// Minimum Spanning Tree
// cost = sum of weights of edges, min cost rakhna hai.


// Minimum Spanning Tree (MST)
// 1. Kruksal Algorithm (Greedy Algorithm)
// 2. Prim's Algorithm (Greedy Algorithm)

// DSU Data Structure
// Path Compression + Union by Rank


class DSU {
	int *parent;
	int *rank;
public:

	DSU(int n) {
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}


	int findSet(int x) {
		if (parent[x] == -1) {
			return x;
		}

		return parent[x] = findSet(parent[x]);
	}


	void unionSet(int x, int y) {
		int parentX = findSet(x);
		int parentY = findSet(y);

		if (parentX != parentY) {
			if (rank[parentX] > rank[parentY]) {
				parent[parentY] = parentX;
			} else {
				parent[parentX] = parentY;
			}
		}
	}

};


class Graph {
	vector<vector<int>> edgeList;
	int V;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int weight) {
		edgeList.push_back({weight, x, y});
	}

	int kruskal_mst() {
		// Main Logic - Easyy
		// 1. Sort all the edges.
		sort(edgeList.begin(), edgeList.end());

		// Initialize DSU
		DSU s(V);

		int ans = 0;
		for (auto edge : edgeList) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			if (s.findSet(x) != s.findSet(y)) {
				s.unionSet(x, y);
				ans += w;
			}
		}

		return ans;
	}
};
