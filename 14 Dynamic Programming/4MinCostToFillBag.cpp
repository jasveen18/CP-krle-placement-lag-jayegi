// T - O(N * W)
// S - O(N * W)
int minimumCost(int cost[], int N, int W) {
	vector<int> val;
	vector<int> weight;

	// Get the value and weight of valid items
	for (int i = 0; i < N; i++) {
		if (cost[i] != -1) {
			weight.push_back((i + 1));
			val.push_back(cost[i]);
		}
	}

	int n = val.size();
	// Initialization
	vector<vector<long long int>> dp(n + 1, vector<long long int> (W + 1, INT_MAX));

	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;

	for (int j = 0; j <= W; j++) {
		dp[0][j] = INT_MAX;
	}


	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if (j - weight[i - 1] >= 0) {
				dp[i][j] = min(dp[i - 1][j], val[i - 1] + dp[i][j - weight[i - 1]]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][W] == INT_MAX ? -1 : dp[n][W];
}