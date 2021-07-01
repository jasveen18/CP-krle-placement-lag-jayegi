/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Create a graph and print it.

class Graph {
private:
	int V; // Number of vertices
	list<int> *adjList; // Adj list for each vertex

public:
	// Constructor
	Graph(int V) {
		this->V = V;
		adjList = new list<int>[V];
	}

	void addEdge(int x, int y, bool bidir = False) {
		adjList[x].push_back(y);

		if (bidir)
			adjList[y].push_back(x);
	}

	void printAdjList() {
		// Iterate over all vertices and print it
		for (int i = 0; i < V; i++) {
			cout << "Vertex: " << i << "-> ";

			for (int nbr : adjList[i])
				cout << nbr << ", ";

			cout << endl;
		}
	}
};