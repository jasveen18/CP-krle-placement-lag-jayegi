# Min Number of coins to change to reach the target amount, given denomination
# We can use any number of coins of one thing.


# O(N) time | O(N) space
def minNumberOfCoins(coins: list) -> int:
	dp = [float("inf") for _ in range(n+1)]

	for i in range(n+1):
		for coin in coins:
			if i - coin >= 0:
				dp[i] = min(dp[i], dp[i - coin])

	return dp[n]