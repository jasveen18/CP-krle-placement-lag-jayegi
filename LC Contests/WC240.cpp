/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/


// 1. 1854. Maximum Population Year
int maximumPopulation(vector<vector<int>>& logs) {
	int n = logs.size();
	if (n == 0)
		return 0;

	// {count, year}
	vector<int> yearCount(101, 0);

	// Bruteforce
	for (int i = 0; i < n; i++) {
		for (int j = logs[i][0]; j < logs[i][1]; j++) {
			yearCount[j - 1950]++;
		}
	}

	// Find max
	int maxCount = 0;
	int maxYear = 0;

	for (int i = 0; i < yearCount.size(); i++) {
		if (yearCount[i] > maxCount) {
			maxCount = yearCount[i];
			maxYear = i + 1950;
		}
	}

	return maxYear;
}


// 2.1855. Maximum Distance Between a Pair of Values
int maxDistance(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();

	int i = n - 1, j = m - 1;
	int maxDist = 0;

	// nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
	// i<=j and nums1[i] <= nums2[j]
	// (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
	while (i >= 0 and j >= 0) {
		while (j >= 0 and nums1[i] > nums2[j])
			j--;

		maxDist = max(maxDist, j - i);
		i--;
	}

	return maxDist;
}


// 3. 1856. Maximum Subarray Min-Product
int maxSumMinProduct(vector<int>& nums) {
	int n = nums.size();
	stack< pair<long long, int> > nsl;
	stack< pair<long long, int> > nsr;

	vector<int> idxNSL;
	vector<int> idxNSR;

	// NSL find kr lete hai
	for (int i = 0; i < n; i++) {
		if (nsl.empty())
			idxNSL.push_back(0);
		else {
			while (nsl.empty() == false and nsl.top().first >= nums[i])
				nsl.pop();

			if (nsl.empty())
				idxNSL.push_back(0);
			else
				idxNSL.push_back(nsl.top().second);
		}

		nsl.push({nums[i], i});
	}

	// NSR find kr lete hai
	for (int i = n - 1; i >= 0; i--) {
		if (nsr.empty())
			idxNSR.push_back(n);
		else {
			while (nsr.empty() == false and nsr.top().first >= nums[i])
				nsr.pop();

			if (nsr.empty())
				idxNSR.push_back(n);
			else
				idxNSR.push_back(nsr.top().second);
		}

		nsr.push({nums[i], i});
	}
	reverse(idxNSR.begin(), idxNSR.end());

	vector<long long> prefixSum(n + 1, 0);

	for (int i = 0; i < n; i++)
		prefixSum[i + 1] = prefixSum[i] + nums[i];
	// prefixSum[n+1] = prefixSum[n];

	long long res = INT_MIN;
	int mod = 1e9 + 7;

	for (int i = 0; i < n; i++) {
		int left = idxNSL[i];
		int right = idxNSR[i];
		long long valHere = nums[i] * (prefixSum[right] - prefixSum[left]);
		cout << valHere << endl;

		res = max(res, valHere) % mod;
	}

	return res % mod;
}




// 4. 1857. Largest Color Value in a Directed Graph OP OP
// Approach 1 - Using DFS
bool findCycle(int src, vector<list<int>> &adjList, vector<bool> &visited, vector<bool> &path) {
	visited[src] = true;
	path[src] = true;

	for (int nbr : adjList[src]) {
		if (path[nbr] == true)
			return true;

		if (visited[nbr] == false) {
			bool cycleSmaller = findCycle(nbr, adjList, visited, path);
			if (cycleSmaller)
				return true;
		}
	}

	path[src] = false;
	return false;
}
bool isCyclePresent(vector<list<int>> &adjList, int n) {
	vector<bool> visited(n, false);
	vector<bool> path(n, false);

	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			bool cycleMila = findCycle(i, adjList, visited, path);
			if (cycleMila)
				return true;

			path.clear();
		}
	}

	return false;
}


int dfs(int src, string &colors, vector<list<int>>& adjList, vector<vector<int>>& cnt, vector<bool> &visited) {
	visited[src] = true;

	for (int nbr : adjList[src]) {
		// Go deep
		if (visited[nbr] == false)
			dfs(nbr, colors, adjList, cnt, visited);

		// Update the answer for this node, jo bhi niche se aaya
		for (int k = 0; k < 26; k++)
			cnt[src][k] = max(cnt[src][k], cnt[nbr][k]);
	}

	cnt[src][colors[src] - 'a']++;
	return *max_element(cnt[src].begin(), cnt[src].end());
}

int largestPathValue(string colors, vector<vector<int>>& edges) {
	int n = colors.size();
	int size = edges.size();

	// Create adj list
	vector<list<int>> adjList(n);
	for (int i = 0; i < n; i++) {
		adjList[i] = list<int>();
	}

	// Fill the edges in adjList
	for (int i = 0; i < size; i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		adjList[u].push_back(v);
	}

	// Check for cycle
	bool cycle = isCyclePresent(adjList, n);
	if (cycle)
		return -1;

	// DFS and maintain count for every node
	int res = 0;
	vector<bool> visited(n, false);
	vector<vector<int>> cnt(n, vector<int> (26, 0));

	// Process every element
	for (int i = 0; i < n; i++) {
		int temp = 0;
		if (visited[i] == false)
			temp = dfs(i, colors, adjList, cnt, visited);
		res = max(res, temp);
	}

	return res;
}


// Approach 2 - Using Topological Sorting
int largestPathValue(string colors, vector<vector<int>>& edges) {
	int n = colors.size();
	int size = edges.size();

	// Create adj list
	vector<list<int>> adjList(n);
	for (int i = 0; i < n; i++) {
		adjList[i] = list<int>();
	}

	// Fill the edges in adjList
	for (int i = 0; i < size; i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		adjList[u].push_back(v);
	}


	// Topological Sort(BFS) to find the max color freq
	// We will have a count of colors for each node
	vector<int> indegree(n, 0);
	vector<vector<int>> cnt(n, vector<int> (26, 0));

	for (int i = 0; i < size; i++) {
		indegree[edges[i][1]]++;
	}

	vector<int> q;
	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
			q.push_back(i);

	int res = 0, processed = 0;
	while (q.empty() == false) {
		vector<int> nextLevel;

		// Process all nodes in this level
		for (auto node : q) {
			processed++;
			cnt[node][colors[node] - 'a']++; // Increment for this value

			res = max(res, cnt[node][colors[node] - 'a']);

			// Process the neighbors of this node
			for (auto nbr : adjList[node]) {
				// Increment count
				for (int k = 0; k < 26; k++)
					cnt[nbr][k] = max(cnt[nbr][k], cnt[node][k]);

				// Decrease indegree since parent processed
				indegree[nbr]--;
				if (indegree[nbr] == 0)
					nextLevel.push_back(nbr);
			}
		}

		swap(q, nextLevel);
	}

	// If number of processed nodes is equal to number of nodes
	return processed != n ? -1 : res;
}