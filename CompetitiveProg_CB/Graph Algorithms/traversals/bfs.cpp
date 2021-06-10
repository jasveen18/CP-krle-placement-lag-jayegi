// Breadth First Search
// More like Iterative Way.
// Start with a node and go to all it's neighbors.
// We'll use a queue (like a level order traversal in tree)

template<typename T>
class Graph {
	map<T, list<T>> l;

public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src) {
		map<T, int> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			// Operation with node.
			cout << node << " ";

			for (int nbr : l[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
};

// Define Graph like -
// Graph<int> g;