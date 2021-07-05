/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/
void dfsTimeIt(int src, vector<int> adjList[], vector<bool> &vis, int &timer, vector<int> &startTime, vector<int> &endTime) {
	vis[src] = true;
	startTime[src] = timer++;

	for (auto nbr : adjList[src]) {
		if (vis[nbr] == false) {
			dfsTimeIt(nbr, adjList, vis, timer, startTime, endTime);
		}
	}

	endTime[src] = timer++;
}


void isPossibleToFind(int n, vector<pair<int, int>> &edgeList, int q, vector<vector<int>> &queries) {
	// Convert edge list to adj list
	vector<int> adjList[n];
	for (int i = 0; i < edgeList.size(); i++) {
		adjList[edgeList[i].first].push_back(edgeList[i].second);
	}

	vector<bool> vis(n, false);
	vector<int> startTime(n, 0);
	vector<int> endTime(n, 0);
	int timer = 0;

	// Store the start time and end time of the nodes
	dfsTimeIt(0, adjList, vis, timer, startTime, endTime);

	for (int i = 0; i < queries.size(); i++) {
		int dir = queries[i][0], dest = queries[i][1], src = queries[i][2];

		if (dir == 0) {
			if (startTime[src] > startTime[dest] and endTime[src] < endTime[dest])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		} else {
			if (startTime[dest] > startTime[src] and endTime[dest] < endTime[src])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	// cout<<"Test"<<endl;
	return;
}