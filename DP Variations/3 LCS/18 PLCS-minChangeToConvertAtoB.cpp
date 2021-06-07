// *** Minimum Number of Insertion or Deletion to convert A -> B *** //

// Note - This is not Edit Distance, isme bss insert and delete krna hai not replace.
// 1. Problem Statement -
// Insert or Delete some elements from string A, to get string B.

// 2. Similarity -
// DP ka hai ya ni?
// Optimal puch ra hai, ki minimum number chaiye.
// Ab LCS kaise jaane?
// do string die hongi and kuch optimal krne ko bol ra hai, mtlb LCS hai hi hai.


int minNumberChangeAtoB(string x, string y, int n, int m) {
	// LCS hi toh matchi krni hai, pehle A ko LCS bana do, deletion krke.
	// Then insertion kr do LCS ko B pe.
	// A -> LCS -> B => A -> B
	// Therefore, we don't need to operate on LCS, baaki sbko del and ins krna hoga.

	int lcsLen = longestCommonSubseqLen(x, y, n, m);
	int deletions = n - lcsLen;
	int insertions = m - lcsLen;

	return insertions + deletions;
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