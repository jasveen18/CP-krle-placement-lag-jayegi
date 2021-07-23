/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - LIS
int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) dp[i] = max(dp[i], dp[j]);
        }
        // Add current element to subseq
        dp[i]++;
    }

    int longestSubseq = 0;
    for (int i = 0; i <= n; i++)
        longestSubseq = max(longestSubseq, dp[i]);

    return longestSubseq;
}
