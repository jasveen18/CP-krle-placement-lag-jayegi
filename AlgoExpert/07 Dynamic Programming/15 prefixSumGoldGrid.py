def computeGoldGrid(grid):
    """Return the max gold coin you can have among the minimum of four cuts in the grid.
    So, we have to cut the grid into four parts in such a way that we maximize the minimun
    of those four cuts.
    O(N*N) time | O(N*N) space
    """
    r = len(grid)
    c = len(grid[0])

    # Compute the prefix sum of gold coins
    dp = [[0] * c for _ in range(r)]

    dp[0][0] = grid[0][0]
    for i in range(1, r):
        dp[i][0] = dp[i-1][0] + grid[i][0]
    for j in range(1, c):
        dp[0][j] = dp[0][j-1] + grid[0][j]

    for i in range(1, r):
        for j in range(1, c):
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j]

    # After computing the prefix sum, we will try to cut the field at all places
    # and find the desired value, by getting sum in O(1)
    res = -1
    for i in range(1, r):
        for j in range(1, c):
            # We are cutting the field at (i, j)
            firPart = dp[i][j]
            secPart = dp[i][c-1] - dp[i][j]
            thiPart = dp[r-1][j] - dp[i][j]
            fouPart = dp[r-1][c-1] - firPart - secPart - thiPart
            minOfThisCut = min([firPart, secPart, thiPart, fouPart])
            res = max(res, minOfThisCut)

    return res
