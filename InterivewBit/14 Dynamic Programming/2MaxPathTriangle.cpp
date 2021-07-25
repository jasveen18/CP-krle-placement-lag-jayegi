/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find max path sum from top to bottom (not the last index, any index in last row);
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n - 1][n - 1] = A[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
        dp[n - 1][i] = A[n - 1][i];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + A[i][j];
        }
    }

    return dp[0][0];
}
