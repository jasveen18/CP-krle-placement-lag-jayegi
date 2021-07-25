/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Chain of pairs
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();

    vector<int> dp(n + 1, 0);
    int res = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j][1] < A[i][0]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        res = max(res, dp[i]);
    }

    return res;
}
