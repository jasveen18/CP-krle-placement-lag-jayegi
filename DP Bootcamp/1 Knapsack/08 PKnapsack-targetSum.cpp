// *** Target Sum *** //

// 1. Problem Statement -
// Assign sign (+/-) before each element such that sum of the whole array is given value targetSum.
// Return the count of combinations that you can do to achieve this.

// 2. Similarity -
// Same question as count the number of subsets with given diff, just in another language.

// If you will see, last time bhi hmlog kuch elements ko plus pe lere the and kuch ko minus pe.
// Yaha pe + / - hi lagana hai elements pe.

int targetSumChangingSigns(int nums[], int n, int diff) {
	int totalSum = 0;
	for (int i = 0; i < n; i++)
		totalSum += nums[i];

	int targetSum = (totalSum + diff) / 2;
	return countSubsetSum(nums, n, targetSum);

	// If you have zero values in the array, this will be the answer.
	// return countSubsetSum(nums, n, targetSum) * pow(2, countOfZero);
}


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