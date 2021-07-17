/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Only one transaction
int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();

    if (n <= 1)
        return 0;

    vector<int> dp(n, 0);
    dp[0] = A[1] - A[0];
    int maxProfit = max(0, dp[0]);

    for (int i = 1; i < n - 1; i++) {
        dp[i] = A[i + 1] - A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
        maxProfit = max(maxProfit, dp[i]);
    }

    return maxProfit;
}
