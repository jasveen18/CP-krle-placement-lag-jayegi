int longestCommonSubstr (string s1, string s2, int x, int y)
{
    // Initialization
    int dp[x + 1][y + 1];
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i <= x; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= y; j++)
        dp[0][j] = 0;

    // Build up the dp
    int longestStringLen = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                longestStringLen = max(longestStringLen, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return longestStringLen;
}