// Here, the algo is same as the previous one.
// If you will see closely, the dp array is my LIS.
// Therefore, every element in the array is in incresing order.

// Now suppose I encounter a new elemenet, x, and I need to place it
// at its correct position. Why do a linear search when you can easily do binary search.

// Therefore, I'll do upper bound and try to place my element there if possible.
// Last time bhi har element ko utha kr shii range m fit krre the. Idhar bhi voi krre hai,
// just the search operation for shii range is done by using upper_bound.

int longestIncreasingSubsequence(vector<int> &nums) {
	int n = nums.size();
	vector<int> dp(n + 1, 0);

	// Initialization
	dp[0] = INT_MIN;
	for (int i = 1; i <= n; i++)
		dp[i] = INT_MAX;

	// Build up the DP
	for (int i = 0; i < n; i++) {
		int indexToPlace = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
		if (dp[indexToPlace - 1] < nums[i] and nums[i] < dp[indexToPlace]) {
			dp[indexToPlace] = nums[i];
		}
	}

	int longestLen = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] != INT_MAX) longestLen = i;
	}

	return longestLen;
}