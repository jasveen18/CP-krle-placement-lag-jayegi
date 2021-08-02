// 1. 929. Unique Email Addresses
int numUniqueEmails(vector<string>& emails) {
    unordered_map<string, unordered_set<string>> originals;
    // vector<string, string> split;

    // Split each mail into name and domain
    for (int i = 0; i < emails.size(); i++) {
        int rate = 0;
        while (emails[i][rate] != '@')
            rate++;

        string name = emails[i].substr(0, rate);
        string domain = emails[i].substr(rate + 1, emails[i].size() - rate);

        // Now that I have this, I need to clean the name
        string clean = "";
        for (int x = 0; x < name.size(); x++) {
            if (name[x] == '.')
                continue;
            if (name[x] == '+')
                break;

            clean += name[x];
        }

        originals[domain].insert(clean);
    }

    int res = 0;
    for (auto el : originals) {
        res += el.second.size();
    }

    return res;
}


// 3. Min falling path sum
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 1)
        return matrix[0][0];

    vector<vector<int>> dp(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++)
        dp[0][i] = matrix[0][i];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n - 1; j++) {
            dp[i][j] = matrix[i][j] + min(min(dp[i - 1][j - 1], dp[i - 1][j + 1]), dp[i - 1][j]);
        }

        // Boundaries
        dp[i][0] = matrix[i][0] + min(dp[i - 1][1], dp[i - 1][0]);
        dp[i][n - 1] = matrix[i][n - 1] + min(dp[i - 1][n - 2], dp[i - 1][n - 1]);
    }

    int res = INT_MAX;
    for (int i = 0; i < n; i++)
        res = min(res, dp[n - 1][i]);

    return res;
}