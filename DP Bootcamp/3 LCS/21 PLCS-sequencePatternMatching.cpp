// *** Sequence Pattern Matcing *** //

// 1. Problem Statement -
// Is string 'a', a subsequence of 'b'?
// Example - a: AXY
// 			 b: ADXCPY
// Ans -> AXY


// 2. Similarity -
// LCS hi hai bhai, bss length match krni hogi

// Code dekho -
bool matchSequencePattern(string x, string y, int n, int m) {
	// x is the smaller string.
	return n == longestCommonSubseqBottomUp(x, y, n, m);
}


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