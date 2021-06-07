// Approach - DP
// T - O(S * T)
// S - O(S * T)
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> distanceDP(m + 1, vector<int> (n + 1, 0));
    for (int i = 1; i <= m; i++)
        distanceDP[i][0] = i;
    for (int j = 1; j <= n; j++)
        distanceDP[0][j] = j;

    // DP logic
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                distanceDP[i][j] = distanceDP[i - 1][j - 1];
            } else {
                distanceDP[i][j] = min3(distanceDP[i - 1][j - 1],
                                        distanceDP[i][j - 1],
                                        distanceDP[i - 1][j]) + 1;
            }
        }
    }

    return distanceDP[m][n];
}