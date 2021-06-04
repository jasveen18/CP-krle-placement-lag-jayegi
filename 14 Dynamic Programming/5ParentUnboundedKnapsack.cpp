int knapSack(int N, int W, int val[], int wt[]) {
    // Initialization
    int dp[N + 1][W + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= N; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= W; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (j - wt[i - 1] >= 0) {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][W];
}