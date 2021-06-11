// The observation is that, for the outer loop
// we only need values from all columns of previous row.

// Therefore, we can store it in dp[2][n+1]

int longestCommonSubsetSpaceOpt(string x, string y, int n, int m) {
	// Initialization
	vector<int> dp(2, vector < int(n, 0));

	// To know in which row we are right now.
	bool bi;

	for (int i = 0; i <= n; i++) {
		bi = i & 1;

		for (int j = 0; j <= m; j++) {
			if (i == 0 or j == 0)
				dp[bi][j] = 0;

			if (x[i - 1] == y[j - 1])
				dp[bi][j] = dp[1 - bi][j - 1] + 1;
			else
				dp[bi][j] = max(dp[1 - bi][j], dp[bi][j - 1]);
		}
	}

	return dp[bi][n];
}