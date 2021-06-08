# Quick sort
# Pick an element and put it into correct position.
# T - O(N * Log N)
# S - O(1) depending on implementation.
import random


# Quick Sort Algorithm
def quickSort(nums, left=0, right=None):
    # Set right first
    if right == None:
        right = len(nums) - 1

    if left < right:
        partition = partitionList(nums, left, right)

        # Recursive function on both parts of the list
        quickSort(nums, left, partition-1)
        quickSort(nums, partition+1, right)
    return nums


# Do partition
def partitionList(nums, left, right):
    # Pick any random element and set as pivot
    randomPartition(nums, left, right)
    partitionIdx = left  # Index of smaller element
    pivotElement = nums[right]  # Pivot element

    for i in range(left, right):
        # If current element is smaller than pivot
        if nums[i] < pivotElement:
            nums[i], nums[partitionIdx] = nums[partitionIdx], nums[i]
            # Index of smaller element
            partitionIdx += 1

    nums[partitionIdx], nums[right] = nums[right], nums[partitionIdx]
    return partitionIdx


# Random partition to improve worst cases
def randomPartition(nums, left, right):
    pivotIdx = random.randint(left, right)
    nums[left], nums[pivotIdx] = nums[pivotIdx], nums[left]


nums = [4, 6, 2, -1, -8, 0, 1, 3, 0]
print("Before Sorting: ")
print(nums)

nums = quickSort(nums)
print("After Sorting: ")
print(nums)

# Before Sorting:
# [4, 6, 2, -1, -8, 0, 1, 3, 0]
# After Sorting:
# [-8, -1, 0, 0, 1, 2, 3, 4, 6]
