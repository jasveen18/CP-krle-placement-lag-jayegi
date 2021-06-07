/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
* https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
******************************************/

T - O(N * N)
S - O(N * N)

int longestCommonSubseq(string x, string y, int n, int m) {
	// Initialization
	vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= m; j++)
		dp[0][j] = 0;

	// Build up the dp
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n][m];
}