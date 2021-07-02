/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Breadth First Search of a Graph
// Template Function

template<typename T>
class Graph {
private:
	map<T, list<T>> adjList;

public:
	void addEdge(T x, T y, bool bidir) {
		adjList[x].push_back(y);

		if (bidir)
			adjList[y].push_back(x);
	}


	void bfsTraversal(T src) {
		map<T, int> visited;
		queue<T> q;

		// Insert src into queue to start from here.
		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			T currNode = q.front(); q.pop();

			// Operation with the current node, here we will print it.
			cout << currNode << " ";

			// Get all the neighbors of the curr node
			for (auto nbr : adjList[currNode]) {
				// Only process if not visited
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
};


// Define graph like -
// Graph<int> g;