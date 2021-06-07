// T - O(N*N)
// S - O(N*N)
// Function to return max value that can be put in knapsack of capacity W.
int knapSackBottomUp(int maxWeight, int wt[], int val[], int n) {
    // Initialization
    int dp[n + 1][maxWeight + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= maxWeight; j++)
        dp[0][j] = 0;

    // Build Up the DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            // If possible to include to this element, here we have j as weight
            if (wt[i - 1] <= j) {
                // Include case
                int includeCase = dp[i - 1][j - wt[i - 1]] + val[i - 1];

                // Exclude case
                int excludeCase = dp[i - 1][j];

                // Take the maximum of both
                dp[i][j] = max(includeCase, excludeCase);
            } else {
                // If we can't include the element due to high weight.
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][maxWeight];
}


// T - O(N*N)
// S - O(N*N)
// Function to return max value that can be put in knapsack of capacity W.
// dp[100][100] = {-1}; This is just to show, make the global matrix, but initialize in main func
int knapSackTopDown(int maxWeight, int wt[], int val[], int n) {
    // Base Case
    if (n == 0 or maxWeight == 0)
        return 0;

    // Look up memoization
    if (dp[n][maxWeight] != -1)
        return dp[n][maxWeight];

    // Recursive Case
    // If we can include it.
    if (wt[n - 1] <= maxWeight) {
        // Include case
        int includeCase = knapSackTopDown(maxWeight - wt[n - 1], wt, val, n - 1) + val[n - 1];

        // Exclude case
        int excludeCase = knapSackTopDown(maxWeight, wt, val, n - 1);

        return max(includeCase, excludeCase);
    } else {
        return knapSackTopDown(maxWeight, wt, val, n - 1);
    }
}