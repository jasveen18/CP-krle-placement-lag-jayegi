// Recursive Solution -
// pCr(n, 0) = 1
// pCr(n, k) = pCr(n-1, k) + k * p(n-1, k-1)
long long int permutationCoefficientProblem(int n, int r) {
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
			dp[i][j] = ((dp[i - 1][j - 1] * j) % mod) + (dp[i - 1][j] % mod) % mod;
		}
	}

	return dp[n][r] % mod;
}