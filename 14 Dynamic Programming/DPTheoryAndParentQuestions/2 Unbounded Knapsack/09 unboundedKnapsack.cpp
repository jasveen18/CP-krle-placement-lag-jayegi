// *** Unbounded Knapsack Problem ***//

// 1. Rod Cutting
// 2. Coin Change I
// 3. Coin Change II
// 4. Maximum Ribbon Cut

// Yaha pe bhi items dia huahai, with weight and value.
// 0-1 Knapsack pe we had 2 choice, we take it or leave and then move on.
// In Unbounded knapsack, we can take the item more than one time. Multiple occurances.
// We take the item and again consider it for our knapsack.

// When we decide ki ni lenge, then it is processed. If le lia toh wapis se consider kro.

int unboundedKnapsack(int wt[], int val[], int n, int maxWeight) {
	// Initialization
	vector<vector<int>> dp(n + 1, vector<int> (maxWeight + 1, -1));

	// Base condition
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= maxWeight; j++)
		dp[0][j] = 0;

	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= maxWeight; j++) {
			if (wt[i - 1] <= j) {			// Yaha pe i hoga instead of (i-1), same element ko consider kro
				dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]],
				               dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][maxWeight];
}