template <typename T>
class Graph {
	unordered_map<T, list<pair<T, int>>> m;

public:
	void addEdge(T u, T v, int dist, bool bidir = true) {
		m[u].push_back({v, dist});
		if (bidir) {
			m[v].push_back({u, dist});
		}
	}


	void printAdj() {
		for (auto j : m) {
			cout << j.first << "->";

			for (auto l : j.second) {
				cout << "(" << l.first << ", " << l.second << "), ";
			}

			cout << endl;
		}
	}

	void djikstra(T src) {
		unordered_map<T, int> dist;

		// Set all distance to infinity
		for (auto j : m) {
			dist[j.first] = INT_MAX;
		}

		// Make a set to find out the node with min dist.
		// Use weight as first parameter to sort acc to that.
		set<pair<int, T>> s;
		dist[src] = 0;
		s.insert({0, src});

		while (!s.empty()) {
			auto p = *(s.begin());

			T node = p.second;
			int nodeDist = p.first;
			s.erase(s.begin());

			// Iterate over the nbrs of current node.
			for (auto childPair : m[node]) {
				if (nodeDist + childPair.second < dist[childPair.first]) {
					// We can't do updation in the element,
					// so we will pop and then push again in the data,
					// to simulate updation.
					T dest = childPair.first;
					auto f = s.find({dist[dest], dest});
					if (f != s.end()) {
						s.erase(f);
					}

					dist[dest] = nodeDist + childPair.second;
					s.insert({dist[dest], dest});
				}
			}
		}


		// Let's print all the distance to all other things.
		for (auto d : dist) {
			cout << d.first << " is located at a distance of " << d.second << " from source." << endl;
		}
	}
};