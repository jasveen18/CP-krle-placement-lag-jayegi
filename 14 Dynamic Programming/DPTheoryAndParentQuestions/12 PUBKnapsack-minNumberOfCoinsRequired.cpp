// *** Minimum Number of Coins *** //

// 1. Problem Statement -
// Minimum number of coins required to get the value.

// 2. Similarity -
// Unbounded knapsack hai, pehle dekh lie the.

// Approach -
// Here we have a tricky initialization.
// Pehle top row ko INTMAX se bhar do. Pehle column ko 0 se bhar do. You know kyun.
// But here, we will have fill the 2nd row also.

int minCoinsToCoinChange(int coins[], int n, int coinValue) {
	// Initialization
	int dp[n + 1][coinValue + 1];
	memset(dp, 0, sizeof(dp));

	// Empty subset pe toh koi coin value ni milegi, so we take inf coins and make it.
	for (int j = 0; j <= coinValue; j++)
		dp[0][j] = INT_MAX - 1;
	// Kyunki empty subsets honge when coinValue is 0, therefore 0 coins.
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;

	// Focus here //
	// 2nd row bhi initialize krre hai
	for (int j = 1; j <= coinValue; j++) {
		if (j % coins[0] == 0)
			dp[1][j] = j / coins[0];
		else
			dp[1][j] = INT_MAX - 1;
	}

	// Build up the DP
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= coinValue; j++) {
			if (coins[i - 1] <= j) {
				dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][coinValue];
}