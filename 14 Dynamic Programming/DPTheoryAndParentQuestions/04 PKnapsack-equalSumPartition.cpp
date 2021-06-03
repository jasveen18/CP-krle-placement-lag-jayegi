// *** Equal Sum Partition *** //

// 1. Problem Statement -
// Divide the array into two 2 subsets such that both have equal sum.
// Return true or false

// 2. Similarity -
// Subset ka sum nikalna hai ki ban payega ya ni?

bool equalSumPartition(int nums[], int n) {
	long long int totalSum = 0;

	for (int i = 0; i < n; i++)
		totalSum += nums[i];

	// If it is odd sum, we can't divide.
	if (totalSum & 1)
		return false;

	// We only need to find if any subset makes half sum.
	int sumToFind = totalSum / 2;
	return subsetSumPossible(nums, n, sumToFind);
}


bool subsetSumPossible(int nums[], int n, int targetSum) {
	// Initialization
	bool dp[n + 1][targetSum + 1];
	memset(dp, false, sizeof(dp));

	for (int j = 0; j <= targetSum; j++)
		dp[0][j] = false;

	for (int i = 0; i <= n; i++)
		dp[i][0] = true;


	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= targetSum, j++) {
			if (nums[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j - nums[i - 1]] or dp[i - 1][j];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][targetSum];
}