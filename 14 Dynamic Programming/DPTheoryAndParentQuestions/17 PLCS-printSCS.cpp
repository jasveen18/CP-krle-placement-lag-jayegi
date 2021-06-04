// *** Print the Shortest Common Subsequence *** //

// 1. Problem Statement -
// Print the SCS of two strings.

// 2. Similarity -
// It is the same question, bss print krni hai hme.

// Pehle LCS wali matrix bana lo.
// Phir LCS string jaise nikalte hai waise hi path trace krenge, with a little modification.
// The modification is that we will include all the chars in the path.

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
			if (dp[i][j - 1] > dp[i - 1][j]) {
				lcs += y[j - 1];
				j--;
			}
			else {
				lcs += x[i - 1];
				i--;
			}
		}
	}

	// We have to check if i > 0 or j > 0 as there is chance that few chars are left.
	while (i > 0)
		lcs += x[i - 1];
	while (j > 0)
		lcs += y[j - 1];

	// Niche se start krre the isliye reversed LCS aaya.
	reverse(lcs.begin(), lcs.end());
	return lcs;
}