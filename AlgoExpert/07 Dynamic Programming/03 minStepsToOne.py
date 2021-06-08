def minStepsTopDown(n: int, dp: list) -> int:
    """
    Function to calculate min steps to one.
    Top Down Recursive Approach using DP
    O(N) time | O(N) space
    args: 
        n step
        dp list
    returns:
        min steps to reach one following conditions
    """

    # Base Case
    if n == 1:
        return 0

    # Look up the table
    if dp[n] != 0:
        return dp[n]

    stepsFromThree = 999999  # INF
    stepsFromTwo = 999999    # INF
    stepsFromOne = 999999    # INF

    # Recursive Cases
    if n % 3 == 0:
        stepsFromThree = minStepsTopDown(n // 3, dp)
    if n % 2 == 0:
        stepsFromTwo = minStepsTopDown(n // 2, dp)
    stepsFromOne = minStepsTopDown(n - 1, dp)

    # Pick min steps
    dp[n] = min(stepsFromOne, min(stepsFromTwo, stepsFromThree)) + 1
    return dp[n]


def minStepsBottomUp(n: int) -> int:
    """
    Function to calculate min steps to one.
    Bottom Up Approach using DP List
    O(N) time | O(N) space
    args: 
        n step
    returns:
        min steps to reach one following conditions
    """
    # Pick initial values
    dp = [0] * (n+1)
    dp[1] = 0

    for i in range(2, n+1):
        stepsFromOne, stepsFromTwo, stepsFromThree = [999999] * 3    # INF

        # Take the previously computed values
        if i % 3 == 0:
            stepsFromThree = dp[i // 3]
        if i % 2 == 0:
            stepsFromTwo = dp[i // 2]
        stepsFromOne = dp[i - 1]

        # Update values of current step
        dp[i] = min(stepsFromOne, min(stepsFromTwo, stepsFromThree)) + 1

    return dp[n]


n = 10
dp = [0] * (n+1)
print(minStepsTopDown(n, dp))
print(minStepsBottomUp(n))
