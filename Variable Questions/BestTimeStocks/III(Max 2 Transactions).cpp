/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Atmost 2 transaction
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Kisi bhi din sell krna mandatory hai toh, best buy price kya hoga? pehle ke prices m sbse kam.
// Vaise hi har din ko mandatory krke best profit nikal skte hai.

// Ye algo laga hai 1 transaction pe.

// Ab kya krenge?
// Iss baari hmlog ith tk max profit kitna hoga? // Pehle (prices[i] - leastPrice) krre the
// Ab max(maxProfit, prices[i] - leastPrice) ye store krenge

// Ab hmlog ulta chal lenge, same max profit nikalte hue from last index to 0.
// And idhar buy mandatory krenge and maxPriceAfter - prices[i] lenge

// Har index pe 2 values hai uss din ke pehle buy sell khatam ho jaaye toh max profit hai
// And uss din ke baad ek buy sell hua toh max profit.
// Non-overlapping transactions hai.

// ---------------------------------------------------------
// Approach 1 - O(N) Time | O(N) space | 3 passes
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	vector<int> left(n, 0);
	vector<int> right(n, 0);

	// Sell mandatory today, toh max profit kitna kr skte
	int leastBefore = prices[0];
	for (int i = 1; i < n; i++) {
		leastBefore = min(leastBefore, prices[i]);
		left[i] = max(left[i - 1], prices[i] - leastBefore);
	}

	// Buy mandatory today, toh max profit kitna kr skte
	int maxAfter = prices[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		maxAfter = max(maxAfter, prices[i]);
		right[i] = max(right[i + 1], maxAfter - prices[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, left[i] + right[i]);

	return ans;
}
// ---------------------------------------------------------

// Brute se start krke optimize krte hai ->
// This is for k transactions.

// kth transaction hai ye
// jth day pe buy and ith day pe sell krte hai toh profit =
// prices[i] - prices[j] + dp[k-1, j-1]. (dp[k-1][j-1]) is the max profit for k-1 transactions till (j-1)th day

// dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]) where j < i
// 	               ye hai agar koi trade ni kie aaj.


// Approach 1
// O(k * n*n) Time | O(k * n) space
int maxProfit(vector<int>& prices) {
	// k is 2 for this question
	int K = 2;
	int n = prices.size();

	vector<vector<int>> dp(K + 1, vector<int> (n));

	for (int k = 1; k <= K; k++) {
		for (int i = 1; i < n; i++) {

			// // For first index
			// dp[k][i] = max(dp[k][i - 1], prices[i] - prices[0]);
			// // For rest of the recurrence
			// for (int j = 1; j <= i; j++) {
			// 	dp[k][i] = max(dp[k][i - 1], prices[i] - prices[j] + dp[k - 1][j - 1]);
			// }

			int minPriceBefore = prices[0];
			for (int j = 1; j <= i; j++)
				minPriceBefore = min(minPriceBefore, prices[j] - dp[k - 1][j - 1]);

			dp[k][i] = max(dp[k][i - 1], prices[i] - minPriceBefore);
		}
	}

	return dp[2][n - 1];
}

// Optimization, -> we can store the minPriceBefore and not calculate it again and again
// O(k * n) time | O(k * n) Space
int maxProfit(vector<int>& prices) {
	// k is 2 for this question
	int K = 2;
	int n = prices.size();

	vector<vector<int>> dp(K + 1, vector<int> (n));

	for (int k = 1; k <= K; k++) {
		int minPriceBefore = prices[0];

		for (int i = 1; i < n; i++) {
			minPriceBefore = min(minPriceBefore, prices[i] - dp[k - 1][i - 1]); // Optimized
			dp[k][i] = max(dp[k][i - 1], prices[i] - minPriceBefore);
		}
	}

	return dp[2][n - 1];
}


// Now, swapping the 2 loops, prices upar hoga, phir transactions
// O(k*n) Time | O(k*n) space
int maxProfit(vector<int>& prices) {
	// k is 2 for this question
	int K = 2;
	int n = prices.size();

	vector<vector<int>> dp(K + 1, vector<int> (n));

	// Make min array to store the min prices
	vector<int> minPrice(K + 1);
	for (int i = 0; i <= K; i++)
		minPrice[i] = prices[0];

	for (int i = 1; i < n; i++) {
		for (int k = 1; k <= K; k++) {
			minPrice[k] = min(minPrice[k], prices[i] - dp[k - 1][i - 1]);
			dp[k][k] = max(dp[k][i - 1], prices[i] - minPrice[k]);
		}
	}

	return dp[K][n - 1];
}

// Now we see that the dp is only dependant on (i-1). Therefore, we can compact this
// O(k*n) time | O(k) space
int maxProfit(vector<int>& prices) {
	// k is 2 for this question
	int K = 2;
	int n = prices.size();

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


// This can be written in much better words like this ->
// This is the final solution ->

int maxProfit(vector<int> &prices, int res = 0) {
	// Function to calculate the profit for infinite transactions
	for (int i = 1; i < prices.size(); i++) res += max(0, prices[i] - prices[i - 1]);
	return res;
}

int maxProfit(int k, vector<int> &prices) {
	int n = prices.size();
	if (k >= n / 2) return maxProfit(prices); // This is the case of infinite transactions, since k >= n/2 toh har din kr skte hai.

	vector<int> buy(k + 1);
	for (int i = 0; i <= k; i++)
		buy[i] = prices[0];
	vector<int> sell(k + 1, 0);

	for (int i = 0; i < n; i++) {
		for (int x = 1; x <= k; x++) {
			buy[x] = min(buy[x], prices[i] - sell[x - 1]);
			//                      pichla sell se kitna min jaa skte hai
			sell[x] = max(sell[x], prices[i] - buy[x]);
			//                      iss transaction ka buy price jo hai toh sell krdo
		}
	}

	return sell[k];
}