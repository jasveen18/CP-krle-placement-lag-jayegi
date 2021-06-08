def valentineMagic(chocolates: list, candies: list, dp: list, i, j):
    """Return the min number of absolute difference elements of one array to second array.
    The size of arrays are different.
    O(N*N) time | O(N*N) space"""
    # If we matched all boys
    if i == len(chocolates):
        return 0

    # If no girls are there, reject this answer
    if j == len(candies):
        return 99999999

    # Look up table
    if dp[i][j] != -1:
        return dp[i][j]

    # Recursive Case
    takeGirl = abs(chocolates[i] - candies[j]) + \
        valentineMagic(chocolates, candies, dp, i+1, j+1)
    dontTakeGirl = valentineMagic(chocolates, candies, dp, i, j+1)

    dp[i][j] = min(takeGirl, dontTakeGirl)
    return dp[i][j]


def main():
    chocolates = [4, 5]
    candies = [1, 2, 3, 4, 6]
    chocolates.sort()
    candies.sort()

    dp = [[-1] * 500 for _ in range(500)]
    print(valentineMagic(chocolates, candies, dp, 0, 0))


main()
