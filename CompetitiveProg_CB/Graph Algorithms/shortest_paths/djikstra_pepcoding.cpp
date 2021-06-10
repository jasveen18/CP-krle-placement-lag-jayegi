// template <typename T>
class Pair {
public:
	string vertex;
	string path_so_far;
	int weight_so_far;

	Pair(string v, string psf, int wsf) {
		vertex = v;
		path_so_far = psf;
		weight_so_far = wsf;
	}
};


struct LessWeight {
	bool operator()(const Pair& one, const Pair& two) {
		return one.weight_so_far < two.weight_so_far;
	}
};


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

	// Same as BFS, but instead of using Queue, we use Priority Queue.
	void djikstra(T src) {
		priority_queue<Pair, vector<Pair>, LessWeight> pq;

		pq.push(Pair(src, src + "", 0));

		unordered_map<T, bool> visited;

		while (pq.size() > 0) {
			Pair rem = pq.top();
			pq.pop();

			if (visited[rem.vertex] == true) {
				continue;
			}

			visited[rem.vertex] = true;
			cout << rem.vertex << " via " << rem.path_so_far << " @ " << rem.weight_so_far << endl;

			for (auto e : m[rem.vertex]) {
				if (visited[e.first] == false) {
					pq.push(Pair(e.first, rem.path_so_far + "->" + e.first, rem.weight_so_far + e.second));
				}
			}
		}


	}
};