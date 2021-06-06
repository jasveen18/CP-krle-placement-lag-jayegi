// *** Rod Cutting Problem *** //

// 1. Problem Statement
// A rod is given of length len, cut the rod into as many pieces as you want.
// For each length there is a price given that you will get if you sell a rod of that length.
// Maximize the profit.
// Length ka array, price ka array and len (length of rod) dia hai.
// Return int, max profit.

// 2. Similarity -
// Exactly same as knapsack.
// length array -> weight array
// price array -> value array

// Ek length pe multiple cuts kr skte hai, therefore, unbounded knapsack


// Code krte hai -
int rodCutting(int length[], int price[], int n, int lengthOfRod) {
	// Initialization
	vector<vector<int>> dp(n + 1, vector<int> (lengthOfRod + 1, -1));

	// Base condition
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= lengthOfRod; j++)
		dp[0][j] = 0;

	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= lengthOfRod; j++) {
			if (length[i - 1] <= j) {			// Yaha pe i hoga instead of (i-1), same element ko consider kro
				dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]],
				               dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][lengthOfRod];
}