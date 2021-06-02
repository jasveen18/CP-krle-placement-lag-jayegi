// *** Subset Problem *** //

// 1. Problem Statement
// Given an array nums and a value x, we need to find if there is a subset which sums to x.
// Returns True or False

// 2. Similarity kaise hai?
// Knapsack pe 2 array dia hota hai, choice hoti hai, ya toh choose krna hai ya ni krna hai.
// Yaha pe bhi sum banane ko koi ek element le ya ni le.

// Now, code variations - matlab actual coding for solving this problem

int subsetSumPossible(int nums[], int n, int targetSum) {
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