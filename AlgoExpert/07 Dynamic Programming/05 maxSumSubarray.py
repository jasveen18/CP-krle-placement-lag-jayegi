def maxSumSubarray(nums: list) -> int:
    """
    Function to return max sum subarray
    O(N) time | O(N) space
    """
    # Initialize Values
    dp = [0] * (len(nums) + 1)
    dp[0] = nums[0] if nums[0] > 0 else 0

    maxSoFar = dp[0]

    for i in range(1, len(nums)):
        dp[i] = dp[i-1] + nums[i]

        # If it becomes negative, then initialize as zero
        if dp[i] < 0:
            dp[i] = dp[i]

        maxSoFar = max(maxSoFar, dp[i])

    return maxSoFar


def maxSumSubarraySpaceOpt(nums: list) -> int:
    """
    Function to return max sum subarray - Kadane's Algorithm
    O(N) time | O(1) space
    """
    currSum = nums[0]
    maxSoFar = nums[0]

    for el in nums:
        currSum = max(nums[0], currSum + nums[0])
        maxSoFar = max(currSum, maxSoFar)

    return maxSoFar
