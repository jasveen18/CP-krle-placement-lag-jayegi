// There are 4 solutions to Longest Increasing Subsequence
// 1. DP - 1 (standard)
// 2. DP - 2 (little tricky)
// 3. DP - 2 with binary search
// 4. DP with segment trees

// Problem Statement - Given array, find subsequences such that they are in increasing order.
// Take the longest (number of elements) among them.

// Approach 1 -
// O(N^2) Time | O(N) Space

// Recurrance relation -
// dp[i] = for all j=0 to j=i-1, max(dp[j]) + 1, where j<i and a[j] < a[i].


int longestIncreasingSubsequence(vector<int> &nums) {
	int n = nums.size();
	vector<int> dp(n + 1, 0);

	// Build up the DP
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i]) dp[i] = max(dp[j], dp[i]);
		}

		// Add the current element to the subseq
		dp[i]++;
	}

	int longestSubseq = 0;
	for (int i = 0; i <= n; i++) {
		longestSubseq = max(longestSubseq, dp[i]);
	}
}

