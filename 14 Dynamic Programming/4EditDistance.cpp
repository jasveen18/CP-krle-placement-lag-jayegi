#define min3(a, b, c) min(a, min(b, c))
int editDistance(string word1, string word2) {
	// Initialization
	int n = word1.size();
	int m = word2.size();

	vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
	for (int i = 1; i <= n; i++)
		dp[i][0] = i;
	for (int j = 1; j <= m; j++)
		dp[0][j] = j;

	// Build up the dp
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// If not equal then opreation hoga, take the optimal path and add one
			if (word1[i - 1] != word2[j - 1]) {
				dp[i][j] = min3(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
			} else { // If equal hai toh piche wale se le lo answer.
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}

	return dp[n][m];
}