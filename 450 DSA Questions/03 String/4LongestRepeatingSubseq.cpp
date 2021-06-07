/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
* https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
******************************************/

// T - O(N*N)
// S - O(N*N)
// Change in LCS, the index should not match in true case.
int LongestRepeatingSubsequence(string str) {
	// Initialization
	int x = str.size();
	int y = str.size();
	string s1 = str;
	string s2 = str;

	int dp[x + 1][y + 1];
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= x; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= y; j++)
		dp[0][j] = 0;

	// Build up the dp
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			// Extra condition, we don't see when they have same index
			if (s1[i - 1] == s2[j - 1] and i != j)
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[x][y];
}