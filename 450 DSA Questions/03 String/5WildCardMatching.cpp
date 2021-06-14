bool match(string pattern, string wild) {
    int m = pattern.size();
    int n = wild.size();

    bool dp[n + 1][m + 1];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true;
    for (int i = 1; i <= m; i++) {
        if (pattern[i - 1] == '*') {
            dp[0][i] = dp[0][i - 1];
        } else {
            dp[0][i] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pattern[j - 1] == wild[i - 1] or pattern[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] or dp[i - 1][j];
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}