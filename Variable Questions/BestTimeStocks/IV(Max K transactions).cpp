/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Max K Transactions

// Pura solution last question m hai, read that
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