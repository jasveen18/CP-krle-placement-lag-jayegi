# s1 = "ABCD"
# s2 = "ABEDG"

# O/p: 3, "ABD"


def lcsRecursive(s1: str, s2: str, i=0, j=0) -> int:
    """Return the max length of Longest Common Subsequence
    from both strings."""
    # Base Case
    if i == len(s1) or j == len(s2):
        return 0

    # Recursive Case
    # If they match, we can count it as answer
    if s1[i] == s2[j]:
        return 1 + lcsRecursive(s1, s2, i+1, j+1)

    # If they don't match, recursively increment both pointers in 2 cases
    return max(lcsRecursive(s1, s2, i+1, j),
               lcsRecursive(s1, s2, i, j+1))


def lcsTopDownRecursive(s1: str, s2: str, dp: list, i=0, j=0) -> int:
    """Return the max length of Longest Common Subsequence
    from both strings using a Top Down DP."""
    # Base Case
    if i == len(s1) or j == len(s2):
        return 0

    # Look up the table
    if dp[i][j] != -1:
        return dp[i][j]

    # Recursive Case
    # If they match, we can count it as answer
    if s1[i] == s2[j]:
        dp[i][j] = 1 + lcsTopDownRecursive(s1, s2, dp, i+1, j+1)
        return dp[i][j]

    # If they don't match, recursively increment both pointers in 2 cases
    dp[i][j] = max(lcsTopDownRecursive(s1, s2, dp, i+1, j),
                   lcsTopDownRecursive(s1, s2, dp, i, j+1))
    return dp[i][j]


s1 = "ABCD"
s2 = "ABEDG"
dp = [[-1] * len(s2) for _ in range(len(s1))]

print("Length of LCS:", lcsRecursive(s1, s2))
print("Length of LCS by Top Down:", lcsTopDownRecursive(s1, s2, dp))
# Length of LCS: 3
# Length of LCS by Top Down: 3
