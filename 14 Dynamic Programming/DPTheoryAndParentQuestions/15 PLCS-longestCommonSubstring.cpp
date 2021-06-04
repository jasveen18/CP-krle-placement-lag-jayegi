// *** Longest Common Substring *** //

// 1. Problem Statement -
// Given 2 string, find the length of common substring. Substring is the one with no skips.
// PS. LCS ka baat mtlb subsequence ki baat hori hai.

// 2. Similarity -
// Same hi chiz dhundhna hai, bss substring hai idhar.
// Input output bhi same.

// Code likho -
int longestCommonSubstring(string x, string y, int n, int m) {
	// Initialization
	int dp[n + 1][m + 1];
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= m; j++)
		dp[0][j] = 0;

	int longestString = -1;
	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i - 1] == y[i - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				longestString = max(longestString, dp[i][j]);
			} else {
				dp[i][j] = 0;
			}
		}
	}

	return longestString;
}
