/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to find the maximum sum such that no element are adjacent.
int FindMaxSum(int arr[], int n) {
    if (n == 1)
        return arr[0];

    vector<int> dp(n + 2, 0);
    dp[0] = 0;
    dp[1] = arr[0];
    dp[2] = arr[1];

    for (int i = 3; i <= n; i++) {
        // 3 choices, ya toh piche wala looto, ya abhi and uske peeche, ya abhi and peeche ke peeche.
        dp[i] = max(max(arr[i - 1] + dp[i - 2], arr[i - 1] + dp[i - 3]), dp[i - 1]);
    }

    int maxLoot = 0;
    for (int i = 0; i <= n; i++)
        maxLoot = max(maxLoot, dp[i]);

    return maxLoot;
}