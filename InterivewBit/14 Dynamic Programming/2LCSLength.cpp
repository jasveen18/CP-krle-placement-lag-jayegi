/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the size of LCS
int Solution::solve(string A, string B) {
    int n = A.size();
    int m = B.size();

    // Initialize DP
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // DP will have zero at first row and column

    // Build up the dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}
