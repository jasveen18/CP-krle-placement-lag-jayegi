# Question: Count the number of BSTs that can be formed
#           using N nodes, numbered 1...N.
# It will be catalan series.
# Recurance relation is - f(N) = summation(i=1 to N) {f(i-1)*f(N-i)}
# Nth term of this series - 2NCN / (N+1), 2NCN is combination

# Modifications on this -
# 1. Number of binary trees?
# For number of binary trees, we just have to permute every number in each config,
# therefore, it will be n!*2nCn / (n+1).

# 2. Number of unlabelled trees? (unlabelled means there are no value in nodes)
# This is same as catalan numbers.

def catalanRecursive(n: int) -> int:
    """Return the nth catalan number.
    O(N^N) time | O(N) space (recursive stack)"""
    if n <= 1:
        return 1

    # computing the series using recurrance relation
    res = 0
    for i in range(n):
        res += catalanRecursive(i) * catalanRecursive(n-i-1)

    return res


def catalanBottomUp(n: int) -> int:
    """Return the nth catalan number using bottom up DP.
    O(N*N) time | O(N) space"""
    # Initialize values
    dp = [0] * (n+1)
    dp[0], dp[1] = 1, 1

    # Build up the dp
    for i in range(2, n+1):
        for j in range(0, i):
            dp[i] += dp[j] + dp[i-j-1]

    return dp[n]


def catalanCombinatorics(n: int) -> int:
    """Return the nth catalan number.
    O(N) time | O(1) space"""
    catN = nCr(2*n, n) / (n+1)

    return catN


# Helper function to calculate nCr
def nCr(n: int, r: int) -> int:
    res = 1

    # Take smaller of r, and n-r
    if r > (n-r):
        r = (n - r)

    for i in range(r):
        res *= (n-i)
        res /= (i+1)

    return res
