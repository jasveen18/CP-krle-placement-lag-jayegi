// *** Longest Common Subsequence *** //

// 1. Longest Common Substring
// 2. Print LCS
// 3. Shortest Common Supersequence
// 4. Print SCS
// 5. Minimum number of insertions / deletion to a -> b
// 6. Largest Repeating Subsequence
// 7. Length of Largest Subsequence of a which is a substring of b
// 8. Subsequence Pattern Matching
// 9. Count how many times a appear as subsequence in b
// 10. Largest Palindromic Subsequence
// 11. Largest Palindromic Substring
// 12. Count of Palindromic Substring
// 13. Minimum number of deletions in a string to make it palindrome
// 14. Minimum number of insertions in a string to make it palindrome

// Given 2 strings, get the longest common subsequence (can skip elements in between).
// Substring pe there are no skips, continuous hona chaiye.


// Recursive Solution
int longestCommonSubseqRecursive(string x, string y, int n, int m) {
	// Base Case
	if (n == 0 or m == 0)
		return 0;

	// Recursive Case
	if (x[n - 1] == y[m - 1])
		return longestCommonSubseqRecursive(x, y, n - 1, m - 1) + 1;

	int leftPointer = longestCommonSubseqRecursive(x, y, n - 1, m);
	int rightPointer = longestCommonSubseqRecursive(x, y, n, m - 1);

	return max(leftPointer, rightPointer);
}


// Memoization Solution - Top Down
int dp[n + 1][m + 1];
// memset(dp, -1, sizeof(dp)); // This line will be in the driver function.
int longestCommonSubseqTopDown(string x, string y, int n, int m) {
	// Base Case
	if (n == 0 or m == 0)
		return dp[n][m] = 0;

	// Look up at the table
	if (dp[n][m] != -1)
		return dp[n][m];

	// Recursive Case
	if (x[n - 1] == y[m - 1])
		return dp[n][m] = longestCommonSubseqTopDown(x, y, n - 1, m - 1) + 1;

	int leftPointer = longestCommonSubseqTopDown(x, y, n - 1, m);
	int rightPointer = longestCommonSubseqTopDown(x, y, n, m - 1);

	return dp[n][m] = max(leftPointer, rightPointer);
}


// Tabulation Solution - Bottom Up
int longestCommonSubseqBottomUp(string x, string y, int n, int m) {
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