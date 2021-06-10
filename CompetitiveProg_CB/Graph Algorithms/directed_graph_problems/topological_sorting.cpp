// Real world problem
// It is used in dependency.
// You need to sort and know which steps to follow so that
// there are no clashes of dependencies.

// Supppose you want to build Face Recognition
// You need to learn python, data preprocessing, data visualization,
// ML basics, Pytorch, DL, ML, Face Recog algo.
// Here for data preprocessing, and visualization, python is depedence.
// For Ml, python hai; for DL, ML hai; for DL, pytorch hai; for pytorch, python hai.

// Only applicable on directed acyclic graph.


//////////// DFS //////////////
template <typename T>
class Graph {
	map<T, list<T>> l;

public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		// l[y].push_back(x)
	}

	void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering) {
		visited[src] = true;

		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited, ordering);
			}
		}

		// When we see that there are no more operations left,
		// we can push it into the front.
		ordering.push_front(src);
		return;
	}

	void dfs() {
		map<T, bool> visited;
		list<T> ordering;

		for (auto p : l) {
			visited[p.first] = false;
		}


		for (auto p : l) {
			T node = p.first;

			if (!visited[node]) {
				dfs_helper(node, visited, ordering);
			}
		}

		// Finally print or return the list
		for (auto node : ordering) {
			cout << node << " " << endl;
		}
	}
};



/////////////// BFS /////////////
// Here our task is to find the first node,
// which doesn't have any other dependency.
// Concept - Indegree - the number of nodes directing at it.

class Graph {
	list<int> *l;
	int V;

public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
	}

	void topological_graph() {
		int *indegree = new int[V];

		// 0 in degree
		for (int i = 0; i < V; i++) {
			indegree[i] = 0;
		}

		// Update indegree
		for (int i = 0; i < V; i++) {
			for (auto y : l[i]) {
				indegree[y]++;
			}
		}


		queue<int> q;
		// 1. Find nodes with 0 indegree.
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		// Start the queue processing.
		while (q.empty() != true) {
			int node = q.front(); q.pop();
			cout << node << " ";

			// Iterate over nbrs and reduce their indegree.
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}

	}
}