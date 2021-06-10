// Prim's MST Algorithm
// Weighted Undirected Graph
// Greedy Algorithm

// Terms ->
// MST Set = [] // Sets picked till now
// Active Edge // Any edge from vertex in MST set to V. Out of active, we pick lowest.
// MST Edge = [] // An edge that has been used/included till now.

// Algorithm -
// 1. Start from any source vertex
// 2. Out of all the active edges, pick the one with smallest weight.
// 			- select in Y in MST.
// 			- add edges start from Y in the active edge list.
//



class Graph {
	// Adjacency List
	vector<pair<int, int>> *l;
	int V;

public:
	Graph(int n) {
		V = n;
		l = new vector<pair<int, int>> [n];
	}

	void addEdge(int x, int y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}

	int prim_mst() {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

		// Another array
		// Visited array that denotes whether a node is in MST or not
		bool *visited = new bool[V] {0};
		int ans = 0;

		// Begin
		Q.push({0, 0});
		while (!Q.empty()) {
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if (visited[to]) {
				// discard the edge, and continue
				continue;
			}

			// otherwise take the current edge
			ans += weight;
			visited[to] = 1;

			for (auto x : l[to]) {
				if (visited[x.first] == 0) {
					Q.push({x.second, x.first});
				}
			}

		}
	}
};