int mcmTopDown(int arr[], int i, int j, int dp[][]) {
	// Base Case
	if (i >= j)
		return dp[i][j] = 0;

	// Look up the table
	if (dp[i][j] != -1)
		return dp[i][j];

	int ans = INT_MAX;
	// Recursive Case
	for (int k = i; k < j; k++) {
		int tempAns = mcmTopDown(arr, i, k, dp)
		              + mcmTopDown(arr, k + 1, j, dp)
		              + arr[i - 1] * arr[k] * arr[j]; // this is the cost

		int ans = min(tempAns, ans);
	}

	return ans;
}