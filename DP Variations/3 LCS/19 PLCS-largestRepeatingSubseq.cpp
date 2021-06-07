// *** Largest Repeating Subsequence *** //

// 1. Problem Statement
// Find a subseq in the given string, such that it is repeating.
// Example -

// string = A A B E B C D D
// 		    _   _       _
// 		      ^     ^     ^
// Longest subseq will be 3.
// Return 3.
//Ek bhi character overlapping ni honi chaiye.

int largestRepeatingSubsequence(string x, int n) {
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
			// Ye extra condition, if they both are equal then we will skip this.
			if (x[i - 1] == y[j - 1] and i != j)
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[n][m];
}