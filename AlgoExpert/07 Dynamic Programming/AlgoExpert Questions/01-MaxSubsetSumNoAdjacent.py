# Find the maximum sum such that no two elements in the sum is not adjacent.
# [7, 10, 12, 7, 9, 14]
# We will pick, [7, 12, 14] => 33.
# If we pick any other valid combination like -> [7, 12, 9], [7, 7, 14] will give less value of sum.

# O(N) time | O(N) space
def maxSubsetSumNoAdjacent(nums: list) -> int:
	if not len(nums):
		return 0
	if len(nums) == 1:
		return nums[0]

	# Initialization
	maxSums = nums[:]
	maxSums[1] = max(nums[0], nums[1])

	# Build up the dp
	for i in range(2, len(nums)):
		maxSums[i] = max(maxSums[i-1], maxSums[i-2] + nums[i])
	return maxSums[-1]


# O(N) time | O(1) space
def maxSubsetSumNoAdjacent(nums: list) -> int:
	if not len(nums):
		return 0
	if len(nums) == 1:
		return nums[0]

	second = nums[0]
	first = max(nums[0], nums[1])

	for i in range(2, len(nums)):
		current = max(first, second + nums[i])
		second = first
		first = current

	return first