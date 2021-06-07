// *** Shortest Common Supersequence *** //

// 1. Problem Statement
// Merge 2 strings in such a way that we get the first string and second string as subsequence.
// You have find the shortest string.
// Example -
// A - geek
// B - eke
// ans - geeke (this is the shortest)


// 2. Similarity
// We are basically using the characters in LCS only once when making the SCS.

// Code kr denge toh dekhte rhoge -
int shortestCommonSupersequence(string x, string y, int n, int m) {
	// We have to include the LCS characters only once.
	// The answer is -
	// n + m - length(LCS)
	return (n + m) - longestCommonSubseqLen(x, y, n, m);
}


int longestCommonSubseqLen(string x, string y, int n, int m) {
	// Initialization
	int dp[n + 1][m + 1];
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= m; j++)
		dp[0][j] = 0;

	// Build up the dp -> if same then add one
	// else, get the max from both pointers.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[n][m];
}