/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Depth First Search of a Graph
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


	void dfsRecursive(T src, map<T, int> &visited) {
		// Do the operation with the curr node
		cout << src << " ";
		visited[src] = true;

		// Go to the neighbors which are not visited in depth first
		for (auto nbr : adjList[src]) {
			if (!visited[nbr])
				dfsRecursive(nbr, visited);
		}

		return;
	}

	void dfsTraversal(T src) {
		map<T, int> visited;

		dfsRecursive(src, visited);
	}
};


// Define graph like -
// Graph<int> g;