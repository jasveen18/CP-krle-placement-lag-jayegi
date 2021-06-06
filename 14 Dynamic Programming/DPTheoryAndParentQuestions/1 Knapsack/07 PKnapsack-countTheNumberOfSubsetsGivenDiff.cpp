// *** Count the number of subsets of given difference *** //

// 1. Problem Statement -
// Divide the array into two subsets such that their difference is diff.
// And then give the count, ki aise kitne pair of subset hai jinka difference is diff.
// Return int.

// 2. Breakdown -
// Let the sum of first subset be s1
// Let the sum of second subset be s2.
// Given target difference = diff

// We need to find the number of subsets with (s1 - s2) = diff.
// Therefore,

// i.  s1 - s2 = diff
// ii. s1 + s2 = sum(array)

// i + ii =>
// => 2*s1 = diff + sum(array)
// => s1 = (diff + sum(array)) / 2

// Now we can just count the number of subsets where the sum => s1 = (diff + sum(array)) / 2


// 3. Similarity -
// count number of subsets with given difference


int countSubsetWithGivenDifference(int nums[], int n, int diff) {
	int totalSum = 0;
	for (int i = 0; i < n; i++)
		totalSum += nums[i];

	int targetSum = (totalSum + diff) / 2;
	return countSubsetSum(nums, n, targetSum);
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
