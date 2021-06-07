// *** Maximum Ribbon Cut *** //

// 1. Problem Statement -
// Cut a ribbon of length n into lengths of a, b, or c such that the pieces are maximum.

// 2. Similarity -
// Min number of coins ke jagah pe max cuts daalni hai bss

// Code -
int maxRibbonCuts(int n, int a, int b, int c) {
	// Initialization
	vector<int> dp(n + 1, -1);
	dp[0] = 0;

	vector<int> cuts{a, b, c};

	// Build up the DP
	for (int i = 1; i <= n; i++) {
		// Get the max cuts till here.
		for (auto el : cuts) {
			if (i - el >= 0)
				dp[i] = max(dp[i], dp[i - el]);
		}

		// If cut is possible, do one more cut
		if (dp[i] != -1)
			dp[i] += 1;
	}

	return dp[n] == -1 ? 0 : dp[n];
}