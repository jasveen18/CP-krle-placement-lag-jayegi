/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the number of bridges in the graph.
// An edge is called a bridge, if by removing it the graph is divided into two or more components.

// Approach -
// 1. We will use 2 arrays. timeOfInsertion[], lowestTimeOfInsertion[].
// 2. We will start DFS from 1st node, then TOI = 1, and LTOI = 1.
// 3. Update the insertion time and lowest time as 1,1. 2,2. 3,3...
// 4. Then when coming back take the lowest time of its adjacent nodes. That will the LTOI.
// 5. If(LTOI[neighbor] > TIN[Curr]) then wo node is bridge.

// DFS complete hone ke baad update hoga LTOI. So that uska lowest milega.

// O(V + E) Time | O(V)

void printBridges(vector<int> adjList[], int V) {
	vector<int> vis(n); // Visited array for DFS
	vector<int> tin(n); // TimeOfInsertion of a node
	vector<int> low(n); // Lowest Time of Insertion of a node (lowest from neighbors)

	int timer = 0; // To track the current time

	// Call for all nodes.
	for (int i = 0; i < V; i++) {
		if (vis[i] == 0) {
			dfsFindBridge(i, -1, vis, tin, low, adjList, timer);
		}
	}
}


void dfsFindBridge(int src, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adjList[], int &timer) {
	vis[src] = 1;
	tin[src] = timer;
	low[src] = timer; // Lowest pe initially timer hi daal do, baad m minimize krenge
	timer++;

	for (auto nbr : adjList[src]) {
		// If neighbor parent hi hai toh ye bridge ni hoga
		if (nbr == parent)
			continue;

		// Run DFS for neighbors, end se jab wapis aayenge tb operation hoga
		if (vis[nbr] == 0) {
			dfsFindBridge(nbr, src, vis, tin, low, adjList, timer);

			// Minimum of neighbors lere hai.
			low[src] = min(low[src], low[nbr]);

			// Check for bridge
			if (low[nbr] > tin[src]) {
				// cout << nbr << " " << src << endl;
				// count++; // Jo bhi requirement ho question ki
			}
		} else { // If already visited hai toh bss lowest time update krlo
			low[src] = min(low[src], low[nbr]);
		}
	}

}



















