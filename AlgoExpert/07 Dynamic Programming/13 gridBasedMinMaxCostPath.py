def minCostToReachEnd(cost: list):
    """Return the min cost path to reach the end of matrix (grid)
    O(N*N) space | O(N*N) time"""
    r = len(cost)
    c = len(cost[0])

    dp = [[0] * c for _ in range(r)]

    # Build up the initiating values
    dp[0][0] = cost[0][0]
    for j in range(1, c):
        dp[0][j] = dp[0][j-1] + cost[0][j]
    for i in range(1, r):
        dp[i][0] = dp[i-1][0] + cost[i][0]

    # Build up the DP
    for i in range(1, r):
        for j in range(1, c):
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j]

    return dp[r-1][c-1]
