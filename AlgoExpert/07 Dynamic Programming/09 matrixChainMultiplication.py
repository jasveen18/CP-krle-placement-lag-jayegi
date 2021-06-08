def matrixChainMultiplication(dimensions: list) -> int:
    """Return the minimum cost of matrix multiplication, the optimisation here
    is in the order by which you do matrix multiplication."""
    dp = [[0] * 200 for _ in range(200)]
    n = len(dimensions) - 1

    for i in range(1, n):
        r = 0
        c = i
        val = 9999999
        while(c < n):
            for pivot in range(r, c):
                val = min(val, dp[r][pivot] + dp[pivot+1][c] +
                          dimensions[r]*dimensions[pivot+1]*dimensions[c+1])

            dp[r][c] = val
            r += 1
            c += 1

    return dp[0][n-1]
