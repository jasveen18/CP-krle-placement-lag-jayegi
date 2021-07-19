/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Max sum with no adjacent elements
int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    if (n == 0)
        return 0;
    vector<int> dp(n, 0);

    if (n == 1)
        return max(A[0][0], A[1][0]);

    dp[0] = max(A[0][0], A[1][0]);
    dp[1] = max(dp[0], max(A[0][1], A[1][1]));
    int res = dp[1];

    for (int i = 2; i < n; i++) {
        int temp = max(A[0][i], A[1][i]) + dp[i - 2];
        dp[i] = max(dp[i - 1], temp);

        res = max(dp[i], res);
    }

    return dp[n];
}
