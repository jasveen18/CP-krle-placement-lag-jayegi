# Bubble sort
# Put the largest number at end, then move on. We will swap at each stage if the elements are not in desired order.
# T - O(N*N)
# S - O(1)
def bubbleSort(nums):
    # Start loop
    for i in range(len(nums)):
        # We don't need to iterate till end, as those elements are already sorted
        lastSortedIndex = len(nums) - i
        for j in range(0, lastSortedIndex - 1):
            # If elements are not in desired order, swap them
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]


nums = [4, 6, 2, -1, -8, 0, 1, 3, 0]
print("Before Sorting: ")
print(nums)

bubbleSort(nums)
print("After Sorting: ")
print(nums)

# Before Sorting:
# [4, 6, 2, -1, -8, 0, 1, 3, 0]
# After Sorting:
# [-8, -1, 0, 0, 1, 2, 3, 4, 6]
