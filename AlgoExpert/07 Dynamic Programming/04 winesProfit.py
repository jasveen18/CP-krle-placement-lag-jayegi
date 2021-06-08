# Recurrence Relation
# profit (i, j, y) = a[i]*y + profit(i+1, j, y+1)
# profit (i, j, y) = a[j]*y + profit(i, j-1, y+1)


def winesProfitTopDown(prices: list, year: int, i: int, j: int, dp: list) -> int:
    """
    Function to return the max profit from selling wine.
    args: 
    O(N) time | O(N) space
    returns:
        min number of coins
    """
    # Base Case
    if i > j:
        return 0

    # Look up table
    if dp[i][j] != 0:
        return dp[i][j]

    # Recursive Case
    sellF = prices[i]*year + winesProfitTopDown(prices, year+1, i+1, j, dp)
    sellL = prices[j]*year + winesProfitTopDown(prices, year+1, i, j-1, dp)
    dp[i][j] = max(sellF, sellL)
    return dp[i][j]


def winesProfitBottomUp():
    """
    Implement it.
    """
    pass


prices = [2, 3, 5, 1, 4]
y = 1
dp = [[0] * len(prices) for _ in range(len(prices))]
print(winesProfitTopDown(prices, y, 0, len(prices)-1, dp))      # 50
