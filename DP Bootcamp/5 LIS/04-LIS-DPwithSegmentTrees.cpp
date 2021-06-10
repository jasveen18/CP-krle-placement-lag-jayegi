struct fenwick {
	vector<int> f;
	int n;
	void init(int n) {
		this->n = n + 1;
		f.resize(this->n, 0);
	}

	void update(int x, int val) {
		x++; // make it one based index
		while (x < n) {
			f[x] = max(f[x], val);
			x += (x & -x);
		}
	}

	int query(int x) {
		x++;
		int res = 0;
		while (x) {
			res = max(res, f[x]);
			x -= (x & -x);
		}

		return res;
	}
}


int longestIncreasingSubsequence(vector<int> &nums) {
	int n = nums.size();
	fenwick tree;
	tree.init(n);

	vector<pair<int, int>> numsPaired;
	for (int i = 0; i < n; i++) {
		numsPaired[i].first = nums[i];
		numsPaired[i].second = i;
	}

	sort(numsPaired.begin(), numsPaired.end());

	// O(N) then logN two time, then -> O(N Log N)
	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		int val = numsPaired[i].first;
		int idx = numsPaired[i].second;

		// query log(N)
		dp[idx] = tree.query(idx - 1) + 1;
		// update log(N)
		tree.update(idx, dp[idx]);

		// for (int j = 0; j < n; j++)
		// 	cout << dp[j] << " ";
		// cout << endl;
	}

	int longestLen = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] != INT_MAX) longestLen = i;
	}

	return longestLen;
}