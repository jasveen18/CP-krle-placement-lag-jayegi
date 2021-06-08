# Rod Cutting Problem
# N = 8
# Example - 1
# length | 1  2  3  4  5   6   7   8
# price  | 1  5  8  9  10  17  17  20
# Cut the rod in such way, that you maximize profit.

# Add memoization to this solution to get top down DP
def rodCuttingRecursion(prices: list, n: int) -> int:
    """Return the max profit you can get by cutting the rods.
    """
    if n <= 0:
        return 0

    ans = -99999999
    for i, price in enumerate(prices):
        cut = i + 1
        profitForThisCut = prices[i] + rodCuttingRecursion(price, n-cut)
        ans = max(ans, profitForThisCut)

    return ans


def rodCuttingBottomUp(prices: list, n: int) -> int:
    """Return the max profit you can get by using Bottom Up DP."""
    dp = [0] * (n+1)
    dp[0] = 0

    # Build DP
    for lenRod in range(n+1):
        # We will only go till length, because the cut can't be greater than len
        for i in range(lenRod):
            cut = i + 1
            profitForThisCut = prices[i] + dp[lenRod - cut]
            ans = max(ans, profitForThisCut)

        dp[lenRod] = ans

    return dp[n]
