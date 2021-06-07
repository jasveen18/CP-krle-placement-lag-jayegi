// Recursive Solution -
// nCr(n, 0) = nCr(n, n) = 1;
// nCr(n, r) = nCr(n-1, r-1) + nCr(n-1, r)
long long int binomialCoefficientProblem(int n, int r) {
	const int mod = 1e9 + 7;
	// Initialization
	vector<vector<long long int>> dp(n + 1, vector<long long int> (r + 1, 0));
	for (int j = 0; j <= r; j++)
		dp[0][j] = 0;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= r; j++) {
			dp[i][j] = (dp[i - 1][j - 1] % mod) + (dp[i - 1][j] % mod) % mod;
		}
	}

	return dp[n][r] % mod;
}