// *** Minimum Subset Sum Difference ***//

// 1. Problem Statement -
// Divide the array nums into 2 parts such that the abs difference between both subsets are minimum.
// Return int

// 2. Similarity -
// In the equal sum partition, hmara absolute diff was zero. Here we want it to be minimum.
// If zero, thats okay.

// Approach -
// Ek range pe hi lie krega na answer ?
// Extreme values are - ek subset is empty, and the other one has all the elements.
// Therefore, the range of abs difference will lie between [0, sum(nums)].

// Now in this range, we will mark the sums which can be formed by picking some elements.
// Ab take the minimum considering each sum as sum of subset1 and (total - sum) as sum of subset2.

// We will make the subset sum matrix and take the last row as that row considers all the elements.


int minSubsetDiff(int nums[], int n) {
	// Find the range of answer - [0 ... sum(nums)]
	int totalSum = 0;
	for (int i = 0; i < n; i++)
		totalSum += nums[i];

	vector<int> validSums = subsetSumPossible(nums, n, totalSum);
	int minDiff = INT_MAX;

	for (int i = 0; i <= validSums.size(); i++) {
		if (validSums[i])
			minDiff = min(minDiff, abs(totalSum - 2 * i)); // This will check sum(subset2) - sum(subset1)
	}

	return minDiff;
}


vector<int> subsetSumPossible(int nums[], int n, int targetSum) {
	// Initialization
	vector<vector<bool>> dp(n + 1, vector<int>(targetSum + 1, false));

	for (int j = 0; j <= targetSum; j++)
		dp[0][j] = false;

	for (int i = 0; i <= n; i++)
		dp[i][0] = true;


	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= targetSum, j++) {
			if (nums[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j - nums[j]] or dp[i - 1][j];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n];
}