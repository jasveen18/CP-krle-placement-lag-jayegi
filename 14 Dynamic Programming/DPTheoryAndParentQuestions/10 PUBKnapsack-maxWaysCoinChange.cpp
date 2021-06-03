// *** Coin Change - Max number of ways *** //

// 1. Problem Statement -
// There is infinite supply of coin, you need to find number of ways to get x value,
// the coins array is given.
// Return int number of ways.

// 2. Similarity -
// For each coin, we have a choice. Either to include it or not.
// Unbounded coz we can pick one coin multiple times.


// Exactly same as Count Subset Sum, but modify it to be unbounded.

int countSubsetSum(int coins[], int n, int coinValue) {
	// Initialization
	int dp[n + 1][coinValue + 1];
	memset(dp, 0, sizeof(dp));

	// Empty subset pe toh koi coin value ni milegi
	for (int j = 0; j <= coinValue; j++)
		dp[0][j] = 0;
	// Kyunki empty subsets honge when coinValue is 0
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= coinValue; j++) {
			if (coins[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][coinValue];
}