// Knapsack hai kya?
// Let's try to code in knapsack

int subseqProductLessThanK(vector<int> &nums, int k) {
	int n = nums.size();

	// Initialization -
	vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
	// For k = 0.
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	// For empty list, khaali subseq ni lena hai yaha.
	for (int j = 0; j <= m; j++) {
		dp[0][j] = 0;
	}


	// Build up the DP, smaller than k, because equal sign ni chaiye
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < k; j++) {
			if (nums[i - 1] <= j and nums[i - 1] > 0) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j / nums[i - 1]];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][k];
}