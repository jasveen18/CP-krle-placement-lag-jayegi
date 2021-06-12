int maxGoldCoins(vector<vector<int>> &mine) {
	int n = mine.size();
	int m = mine[0].size();

	// Initialize the dp
	vector<vector<int>> dp(n + 2, vector<int> (m + 2, 0));

	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = mine[i - 1][j - 1] + max(dp[i][j - 1],
			                                    max(dp[i - 1][j - 1], dp[i + 1][j - 1]));
		}
	}

	int maxCoins = 0;
	for (int i = 1; i <= n; i++) {
		maxCoins = max(maxCoins, dp[i][m]);
	}

	return maxCoins;
}