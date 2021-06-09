def levenshteinDistance(str1:str, str2:str) -> int:
	"""Return the minimum number of operations (add, delete, replace) to
	convert string1 to string2."""

	# Initialization
	n = len(str1)
	m = len(str2)
	dp = [[0] * (m + 1) for _ in range(n + 1)]
	for i in range(n+1):
		dp[i][0] = i
	for j in range(m+1):
		dp[0][j] = i

	# Build up the DP
	for i in range(1, n+1):
		for j in range(1, m+1):
			if str1[i-1] != str2[j-1]:
				dp[i][j] = min([dp[i-1][j-1], dp[i-1][j], dp[i][j-1]]) + 1
			else:
				dp[i][j] = dp[i-1][j-1]

	return dp[n][m]