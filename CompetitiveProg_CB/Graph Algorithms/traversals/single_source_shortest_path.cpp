// For a unweighted graph, (for weighted we use djisktra)

template<typename T>
class Graph {
	map<T, list<T>> l;

public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src) {
		map<T, int> dist;
		queue<T> q;

		// All other nodes have INT_MAX
		for (T node_pair : l) {
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}

		// Source node is 0 dist from itself
		q.push(src);
		dist[src] = 0;

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			cout << node << endl;

			// Iterate through all the neighbors
			for (int nbr : l[node]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);
					// Update the distance
					dist[nbr] = dist[node] + 1;
				}
			}
		}

		for (auto node_pair : l) {
			T node = node_pair.first;
			int d = dist[node];

			cout << "Node: " << node << " Dist from src: " << d << endl;
		}
	}
};