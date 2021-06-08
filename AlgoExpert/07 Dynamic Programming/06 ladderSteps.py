def laddersTopDown(n: int, k: int, dp: list) -> int:
    """
    Function to return the number of ways to reach the top.
    O(N * K) time | O(N) space
    args:
        n - num of steps
        k - max jump
        dp - list
    return:
        num of ways
    """
    # Base Case
    if n == 0:
        return 1

    # Look up Table
    if dp[n] != 0:
        return dp[n]

    # Recursive Case
    ways = 0
    for i in range(1, k+1):
        if n - i >= 0:
            ways += laddersTopDown(n-i, k, dp)

    dp[n] = ways
    return ways


def laddersBottomUp(n: int, k: int) -> int:
    """
    Function to return the number of ways to reach the top.
    O(N * K) time | O(N) space
    args:
        n - num of steps
        k - max jump
    return:
        num of ways
    """
    # Initialize values
    dp = [0] * (n + 1)
    dp[0] = 1

    for step in range(1, n+1):
        # For this step, try to jump into every step
        for jump in range(1, k+1):
            # If reachable, then add the steps from there
            if step - jump >= 0:
                dp[step] += dp[step-jump]

    return dp[n]


def laddersBottomUpSpaceTimeOptimized(n: int, k: int) -> int:
    """Return the number of ways to reach to top.
    O(N) time | O(N) space
    """
    # Initialize values
    dp = [0] * (n+1)
    dp[0] = dp[1] = 1

    # Make the dp for first k elements
    for i in range(2, k+1):
        dp[i] = 2*dp[i-1]

    # DP for next elements
    for i in range(k+1, n+1):
        dp[i] = 2*dp[i-1] - dp[i-k-1]

    return dp[n]
