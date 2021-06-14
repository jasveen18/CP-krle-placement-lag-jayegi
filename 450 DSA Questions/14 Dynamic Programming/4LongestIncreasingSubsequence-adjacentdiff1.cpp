// Same as LIS
int longestSubsequence(int n, int a[]) {
	vector<int> dp(n + 1, 0);

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (abs(a[i] - a[j]) == 1)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	// Get the longest subsequence
	int longestSubseq = 0;
	for (int i = 0; i <= n; i++)
		longestSubseq = max(longestSubseq, dp[i]);

	return longestSubseq;
}