import time


def fibRecursion(n):
    """
    Function to calculate the nth fibonacci number, without any space.
    O(2^n) time | O(n) space (recursive stack)
    args:
        n - nth term
    return:
        nth fib number
    """
    # Base Case
    if n == 0 or n == 1:
        return n

    ans = fibRecursion(n-1) + fibRecursion(n-2)
    return ans


# Recursion with Memoization
def fibTopDown(n: int, dp: list) -> int:
    """
    Function to calculate Fibonacci Number with top down DP
    O(N) time | O(N) space
    args:
        n - nth fib num
        dp - dp list to store our computed results
    return:
        nth fib number
    """
    # Base Case
    if n == 0 or n == 1:
        return n

    # Look up in memory
    if dp[n] != 0:
        return dp[n]

    # Recursive Case
    dp[n] = fibTopDown(n-1, dp) + fibTopDown(n-2, dp)
    return dp[n]


def fibBottomUp(n: int) -> int:
    """
    Function to calculate Fibonacci Number with bottom up DP
    O(N) time | O(N) space
    args:
        n - nth fib num
    return:
        nth fib number
    """
    # Set initial values
    dp = [0] * (n+1)
    dp[1] = 1

    # Calculate bottom up
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]

    return dp[n]


def fibBottomUpSpaceOptimized(n: int) -> int:
    """
    Function to calculate Fibonacci Number with bottom up DP.
    We don't need whole fib array, we only need two space to compute further.
    O(N) time | O(1) space.
    args:
        n - nth fib num
    return:
        nth fib number
    """

    if n == 0 or n == 1:
        return n

    a = 0
    b = 1
    fibN = 0

    # Compute
    for i in range(2, n+1):
        fibN = a + b
        a, b = b, fibN

    return fibN


def main():
    n = 25

    # Fib Number without any DP approach
    startTime = time.time()
    ans = fibRecursion(n)
    endTime = time.time()
    timeElapsed = round((endTime - startTime) * 1000, 2)
    print(f"{n} fib number: {ans}")
    print(f'Time taken by recursion without memoization: {timeElapsed}')

    # Fib Number with top down DP
    startTime = time.time()
    dp = [0] * (n+1)
    ans = fibTopDown(n, dp)
    endTime = time.time()
    timeElapsed = round((endTime - startTime) * 1000, 2)
    print(f"{n} fib number: {ans}")
    print(
        f'Time taken by recursion with memoization (top down): {timeElapsed}')

    # Fib Number with bottom up DP
    startTime = time.time()
    ans = fibBottomUp(n)
    endTime = time.time()
    timeElapsed = round((endTime - startTime) * 1000, 2)
    print(f"{n} fib number: {ans}")
    print(
        f'Time taken by recursion without memoization (bottom up): {timeElapsed}')


main()
