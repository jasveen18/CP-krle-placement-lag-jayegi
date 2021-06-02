// *** Count of Subsets of a given sum *** //

// 1. Problem statement - Number of subsets with given sum x.
// Return int

// 2. Similarity -
// Earlier it was ki batao subset hai ya ni, ab count puch ra hai, same kaam but different requirement.

// Code krte hai ab -

int countSubsetSum(int nums[], int n, int targetSum) {
	// Initialization
	int dp[n + 1][targetSum + 1];
	memset(dp, 0, sizeof(dp));

	// Kyunki empty subsets honge
	for (int j = 0; j <= targetSum; j++)
		dp[0][j] = 0;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= targetSum; j++) {
			if (nums[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][targetSum];
}