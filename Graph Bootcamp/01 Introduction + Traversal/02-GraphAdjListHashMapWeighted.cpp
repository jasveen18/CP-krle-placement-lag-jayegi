/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Weighted Graph

class Graph {
private:
	unordered_map<string, list<pair<string, int>>> adjList;

public:
	void addEdge(string x, string y, bool bidir, int weight) {
		adjList[x].push_back({y, weight});

		if (bidir)
			adjList[y].push_back({x, weight});
	}


	void printAdjList() {
		// Traverse over all the vertex
		for (auto el : adjList) {

			string source = el.first;
			list<pair<string, int>> neighbors = el.second;

			cout << "Source: " << source << "-> ";

			for (auto nbr : neighbors) {
				string destination = nbr.first;
				int distance = nbr.second;

				cout << "{" << destination << ", " << distance << "}, ";
			}
			cout << endl;
		}
	}
};