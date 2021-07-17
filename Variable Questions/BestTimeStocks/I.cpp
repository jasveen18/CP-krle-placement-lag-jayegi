/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Only one transaction
int maxProfit(vector<int>& prices) {
    int n = prices.size();

    if (n <= 1)
        return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = prices[1] - prices[0];
    int maxProfit = dp[0];

    for (int i = 1; i < n - 1; i++) {
        dp[i] = (prices[i + 1] - prices[i]) + (dp[i - 1] < 0 ? 0 : dp[i - 1]);
        maxProfit = max(maxProfit, dp[i]);
    }

    return max(maxProfit, 0);
}