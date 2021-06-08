def noOfWaysToReachEndRat(grid: list):
    """Return the number of path to reach the end of matrix (grid)
    Rat can only move one step at a time, and there are obstacles in the grid.
    -1 denotes a obstacle
    O(N*N) space | O(N*N) time"""
    r = len(grid)
    c = len(grid[0])

    dp = [[0] * c for _ in range(r)]

    if grid[0][0] == -1:
        return 0

    # Build up the initiating values
    dp[0][0] = 1
    for j in range(1, c):
        if grid[0][j] != -1:
            dp[0][j] = 1
        else:
            break
    for i in range(1, r):
        if grid[i][0] != -1:
            dp[i][0] = 1
        else:
            break

    for i in range(1, r):
        for j in range(1, c):
            if grid[i][j] != -1:
                grid[i][j] = grid[i-1][j] + grid[i][j-1]
            else:   # if we encounter an obstacle, there is no way to reach there.
                grid[i][j] = 0

    return dp[r-1][c-1] if dp[r-c][c-1] != -1 else 0


def noOfWaysToReachEndElephant(grid: list):
    """Return the number of path to reach the end of matrix (grid)
    Rat can only move mutiple steps at a time, and there are obstacles in the grid.
    -1 denotes a obstacle.
    0 1 2 3 4 5
    E ----->4       # One path
    E ->2-->4       # Another path, Count both
    For rat we took the sum of immeadiate two cells, here we will have to
    take sum of all elements present behind and above it.
    O(N*N*N) space | O(N*N) time"""
    r = len(grid)
    c = len(grid[0])

    dp = [[0] * c for _ in range(r)]

    # Build up the initiating values
    dp[0][0] = 1
    for j in range(1, c):
        for k in range(c-1):
            dp[0][j] += dp[0][k]
    for i in range(1, r):
        for k in range(r-1):
            dp[i][0] += dp[k][i]

    for i in range(1, r):
        for j in range(1, c):
            if grid[i][j] != -1:
                for k in range(r-1):
                    dp[i][j] += dp[k][j]
                for k in range(c-1):
                    dp[i][j] + + dp[i][k]
            else:   # if we encounter an obstacle, there is no way to reach there.
                grid[i][j] = 0

    return dp[r-1][c-1] if dp[r-c][c-1] != -1 else 0
