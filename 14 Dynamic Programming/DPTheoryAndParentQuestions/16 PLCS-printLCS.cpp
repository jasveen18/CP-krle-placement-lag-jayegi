// *** Print Longest Common Subsequence *** //

// 1. Problem Statement
// We need to print the LCS this time, last time we only printed the length.

// 2. Similarity -
// LCS hi puch ra hai.

// Pehle toh jaise LCS ka dp bharte hai bhar do.
// Phir starting from dp[n][m], go till dp[0][0]. Path Trace krre hai**.
// If same char hai, then lcs pe add kr do and i-1, j-1, kr do.
// If not, then check krlo ki kaunsa greater hai, udhar ke taraf jao.

string printLCS(string x, string y, int n, int m) {
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

	// Now we will trace the path and build LCS string
	string lcs = "";
	int i = n, j = m;

	while (i > 0 and j > 0) {
		if (x[i - 1] == y[j - 1]) {
			lcs += x[i - 1];
			i--; j--;
		} else {
			if (dp[i][j - 1] > dp[i - 1][j])
				j--;
			else
				i--;
		}
	}

	// Niche se start krre the isliye reversed LCS aaya.
	reverse(lcs.begin(), lcs.end());
	return lcs;
}