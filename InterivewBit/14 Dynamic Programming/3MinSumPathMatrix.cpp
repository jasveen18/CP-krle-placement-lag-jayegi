/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min Sum Path Matrix
int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    // Initialize dp
    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[n - 1][m - 1] = A[n - 1][m - 1];
    for (int i = n - 2; i >= 0; i--) {
        dp[i][m - 1] = dp[i + 1][m - 1] + A[i][m - 1];
    }
    for (int j = m - 2; j >= 0; j--) {
        dp[n - 1][j] = dp[n - 1][j + 1] + A[n - 1][j];
    }

    // Build up dp
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + A[i][j];
        }
    }

    return dp[0][0];
}
