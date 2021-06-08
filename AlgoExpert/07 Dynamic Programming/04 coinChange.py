def coinChangeTopDown(n: int, coins: list, dp: list) -> int:
    """
    Function to return the min number of coins to sum to n.
    O(T*N) time | O(N) space, where T is number of coins in list
    args: 
        n
        coins list denomination of coins
        dp lis
    returns:
        min number of coins
    """
    # Base Case
    if n == 0:
        return 0

    # Look up to dp
    if dp[n] != 0:
        return dp[n]

    minCoins = 99999999
    for coin in coins:
        if n - coin >= 0:
            # Calculate the subproblem and pick the min coins from subproblems
            minCoins = min(minCoins, coinChangeTopDown(n-coin, coins, dp) + 1)

    dp[n] = minCoins
    return dp[n]


def coinChangeBottomUp(n: int) -> int:
    """
    Function to use bottom up approach to calculate coin changes
    O(T*N) time | O(N) space
    args:
        n
    return:
        min number of coins
    """
    # Initialize values
    dp = [0] * (n + 1)
    dp[0] = 0

    for i in range(1, n+1):
        # Make dp[i] = inf as to find the min change required
        dp[i] = 9999999

        for coin in coins:
            # Get the smallest coin change available
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[n]


n = 15
coins = [1, 7, 10]
dp = [0] * (n+1)
print(coinChangeTopDown(n, coins, dp))
print(coinChangeBottomUp(n))
