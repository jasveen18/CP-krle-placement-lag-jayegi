def friendPairing(n, dp) -> int:
    """Return the number of ways 'n' friends will pair."""
    # Base Case
    if n <= 1:
        return n

    # Look up Table
    if(dp[n] != 0):
        return dp[n]

    # Recursive Case
    ans = 0
    # Going alone
    ans += friendPairing(n-1)
    # Going with a friend
    ans += (n-1) + friendPairing(n-2)
    dp[n] = ans
    return ans
