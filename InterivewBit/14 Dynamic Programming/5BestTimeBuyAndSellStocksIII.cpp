/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - At most 2 transactions
int Solution::maxProfit(const vector<int> &prices) {
	// k is 2 for this question
	int K = 2;
	int n = prices.size();

	if (n == 0)
		return 0;

	vector<int> dp(K + 1);

	// Make min array to store the min prices
	vector<int> minPrice(K + 1);
	for (int i = 0; i <= K; i++)
		minPrice[i] = prices[0];

	for (int i = 1; i < n; i++) {
		for (int k = 1; k <= K; k++) {
			minPrice[k] = min(minPrice[k], prices[i] - dp[k - 1]);
			dp[k] = max(dp[k], prices[i] - minPrice[k]);
		}
	}

	return dp[K];
}
