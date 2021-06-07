// 3D matrix
// T - O(n1 * n2 * n3)
// S - O(n1 * n2 * n3)
int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
	int dp[n1 + 1][n2 + 1][n3 + 3];
	memset(dp, 0, sizeof(dp));

	// Build up the dp
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			for (int k = 1; k <= n3; k++) {
				if (A[i - 1] == B[j - 1] and A[i - 1] == C[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				} else {
					vector<int> check{dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]};
					dp[i][j][k] = *max_element(check.begin(), check.end());
				}
			}
		}
	}

	return dp[n1][n2][n3];
}