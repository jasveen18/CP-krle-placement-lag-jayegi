# Number of ways to make change given the denomination of coins.

# O(N) Time | O(N) Space
def numWaysToMakeChange(coins: list, n: int) -> int:
	dp = [0] * (n+1)
	dp[0] = 1

	for i in range(n+1):
		for coin in coins:
			if(i - coin >= 0):
				dp[i] += dp[i-coin]

	return dp[n]