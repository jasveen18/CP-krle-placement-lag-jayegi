/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find number of unique paths in the grid
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    vector<vector<int>> dp(n, vector<int> (m, 0));
    if (A[n - 1][m - 1] == 1)
        return 0;

    dp[n - 1][m - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (A[i][m - 1] == 0)
            dp[i][m - 1] = dp[i + 1][m - 1];
        else
            dp[i][m - 1] = 0;
    }
    for (int j = m - 2; j >= 0; j--) {
        if (A[n - 1][j] == 0)
            dp[n - 1][j] = dp[n - 1][j + 1];
        else
            dp[n - 1][j] = 0;
    }

    // Build up dp
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            if (A[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }

    return dp[0][0];
}
