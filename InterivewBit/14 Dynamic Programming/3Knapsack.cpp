/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Knapsack DP
int Solution::solve(vector<int> &val, vector<int> &weight, int capacity) {
    // Include Exclude principle hai
    int n = val.size();

    vector<vector<int>> dp(n + 1, vector<int> (capacity + 1, -1));

    // Base Condn
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= capacity; j++)
        dp[0][j] = 0;

    // Build up the dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (j >= weight[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + val[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}
