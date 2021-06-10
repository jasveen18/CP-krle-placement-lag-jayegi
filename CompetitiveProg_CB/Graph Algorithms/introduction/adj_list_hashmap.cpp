// Weighted Graph
class Graph {
	// Adj List
	unordered_map<string, list<pair<string, int>>> l;

public:
	void addEdge(string x, string y, bool bidir, int wt) {
		l[x].push_back({y, wt});

		// If bidirectional edge
		if (bidir) {
			l[y].push_back({x, wt});
		}
	}

	void printAdjList() {
		for (auto city : l) {
			string city = p.first;
			list<pair<string, int>> nbrs = p.second;

			for (uato nbr : nbrs) {
				string dest = nbr.first;
				int dist = nbr.second;

				cout << dest << " " << dist << ",";
			}

			cout << endl;
		}
	}

};