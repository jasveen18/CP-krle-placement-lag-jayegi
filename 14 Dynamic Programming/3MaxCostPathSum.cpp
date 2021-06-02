int maximumPath(int N, vector<vector<int>> Matrix) {
    // Initialization
    int dp[N + 2][N + 2];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = Matrix[i - 1][j - 1] +
                       max(dp[i - 1][j],
                           max(dp[i - 1][j + 1], dp[i - 1][j - 1]));
        }
    }

    int maxValue = 0;
    for (int i = 0; i <= N; i++) {
        maxValue = max(dp[N][i], maxValue);
    }

    return maxValue;
}