// Kadane's Algroithm
// In constant space
int maxSubarraySum(int arr[], int n) {
	int maxSoFar = arr[0];
	int maxEnding = arr[0];

	for (int i = 1; i < n; i++) {
		maxSoFar = max(arr[i] + maxSoFar, arr[i]);
		maxEnding = max(maxEnding, maxSoFar);
	}

	return maxEnding;
}


// DP with O(N) space
int maxSubarraySum(int arr[], int n) {
	// Initialization
	int dp[n + 1] = {0};
	dp[0] = arr[0];
	int maxEnding = dp[0];

	// Build up the DP
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		maxEnding = max(maxEnding, dp[i]);
	}

	return maxEnding;
}