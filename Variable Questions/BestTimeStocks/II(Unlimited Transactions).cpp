/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Multiple Transactions, no overlapping
int maxProfit(vector<int>& prices) {
    int res = 0;
    int n = prices.size();

    for (int i = 1; i < n; i++) {
        if (prices[i] - prices[i - 1] > 0)
            res += (prices[i] - prices[i - 1]);
    }

    return res;
}