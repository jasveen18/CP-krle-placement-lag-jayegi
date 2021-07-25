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


