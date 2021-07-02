/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the shortest path.
// ** Dijkstra Algorithm ** //

// Given a graph and a source, find the shortest (weight) path of all the other nodes.

// BFS jaisa hai, queue ke jagah priority queue use krenge.
// Jiski priority kam usko pehle bahar nikalenge.

// We want to store 3 things, where are you? | what is the path? | what is the weight.
// Priority queue pe BFS ka chiz ko daalna and min distance jiss node ka hoga in the queue, usko pehle nikalo

// Code -


// Node to store the values in a priority queue, bundle kr die hai bss.
class Pair {
	int v;
	string pathSoFar;
	int weightSoFar;

	Pair(int v, string psf, int wsf) {
		v = v;
		pathSoFar = psf;
		weightSoFar = wsf;
	}
}


// Comparator function for priority queue
struct LessWeight {
	bool operator() (const Pair& a, const Pair& b) {
		return a.weightSoFar < b.weightSoFar;
	}
}


void dijkstraAlgorithm(int src, int v, vector<pair<int, int>> adjList[]) {
	// PQ inplace of queue for BFS traversal
	priority_queue<Pair, vector<Pair>, LessWeight> pq;
	vector<bool> visited(v, false);

	// Put the first element to start traversal
	pq.push(Pair(src, src + "", 0));
	visited[src] = true;

	while (!pq.empty()) {
		Pair curr = pq.top();
		pq.pop();

		// Just a extra check for pq
		if (visited[curr.v] == true)
			continue;

		// Print the details
		cout << curr.v << " via " << curr.pathSoFar << " @ " << curr.weightSoFar << endl;

		// Check neighbors
		for (auto nbr : adjList[curr.v]) {
			if (visited[nbr] == false) {
				pq.push(Pair(nbr.first, curr.pathSoFar + "->" + nbr.first, curr.weightSoFar + nbr.second))
			}
		}
	}

	return;
}