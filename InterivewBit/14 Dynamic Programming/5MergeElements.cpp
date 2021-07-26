/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - MCM ka question
int minCost(vector<int> &A, int i, int j, vector<vector<int>> &dp) {
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i > j)
        return dp[i][j] = 0;
    if (i == j) {
        return dp[i][j] = 0;
    }
    if (j - i == 1) {
        return dp[i][j] = A[i] + A[j];
    }

    int ans = INT_MAX;
    int sum = A[j];
    for (int k = i; k < j; k++) {
        sum += A[k]; // Prefix sum lena hoga
        int left = minCost(A, i, k, dp);
        int right = minCost(A, k + 1, j, dp);

        ans = min(ans, left + right);
    }

    ans += sum; // Add the prefix sum
    return dp[i][j] = ans;
}

int Solution::solve(vector<int> &A) {
    // MCM laga denge
    vector<vector<int>> dp(A.size() + 1, vector<int> (A.size() + 1, -1));
    return minCost(A, 0, A.size() - 1, dp);
}
