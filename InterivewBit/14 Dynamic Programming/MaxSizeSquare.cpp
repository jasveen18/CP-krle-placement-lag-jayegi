/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Max Size Square
int Solution::solve(vector<vector<int> > &dp) {

    int res = 1;
    int n = dp.size(), m = dp[0].size();

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] == 0) continue;

            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            res = max(res, dp[i][j]);
        }
    }

    return res * res;
}
