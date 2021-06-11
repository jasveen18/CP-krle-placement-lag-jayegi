// Extending on the 2nd approach of LIS

int longestSubsequenceSum(int n, int a[]) {
	// Initialize the dp
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; i++)
		dp[i] = a[i];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] and dp[i] < dp[j] + a[i])
				dp[i] = dp[j] + a[i];
		}
	}

	// Get the longest subsequence
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++)
		maxSum = max(maxSum, dp[i]);

	return maxSum;
}