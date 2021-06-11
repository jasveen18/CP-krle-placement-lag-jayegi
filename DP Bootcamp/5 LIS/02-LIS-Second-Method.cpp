// Here we will change the state of the DP
// dp[i] -> element at which the subseq of length i ends.
// Here i is the length.

// Here more than one element can end at length 'i', right?
// So which element to take?
// Taking the smallest elements makes most sense as it will contribute most to LIS.

// The element to be valid it should be between (dp[i-1] to dp[i]). Tabhi toh rakh payenge
// so that chota bhi ho lekin pichle wale se bada ho.

// Therefore, we will initialize the dp[0] = -inf, dp[1...N] = inf
// So that len 1 ke lie pura number range rhe, uske aage ka phir recurrance rel pe chalega.

// O(N*N) time | O(N) space
int longestIncreasingSubsequence(vector<int> &nums) {
	int n = nums.size();
	vector<int> dp(n + 1, 0);

	// Initialization
	dp[0] = INT_MIN;
	for (int i = 1; i <= n; i++)
		dp[i] = INT_MAX;

	// Build up the DP
	for (int i = 0; i < n; i++) {
		for (int length = 0; length < n; length++) {
			if (dp[length] < nums[i] and nums[i] < dp[length + 1]) {
				dp[length + 1] = nums[i];
			}
		}
	}

	int longestLen = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] != INT_MAX) longestLen = i;
	}

	return longestLen;
}