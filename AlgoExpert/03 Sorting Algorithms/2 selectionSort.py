# Selection sort
# Put the smallest number at first, then move on.
# T - O(N*N)
# S - O(1)
def selectionSort(nums):
    # Start Loop
    for i in range(0, len(nums)):
        minElementIndex = i
        # Find the min element
        for j in range(i, len(nums)):
            if nums[minElementIndex] > nums[j]:
                minElementIndex = j

        # Swap the min element with first element of the unsorted array
        nums[minElementIndex], nums[i] = nums[i], nums[minElementIndex]


nums = [4, 6, 2, -1, -8, 0, 1, 3, 0]
print("Before Sorting: ")
print(nums)

selectionSort(nums)
print("After Sorting: ")
print(nums)

# Before Sorting:
# [4, 6, 2, -1, -8, 0, 1, 3, 0]
# After Sorting:
# [-8, -1, 0, 0, 1, 2, 3, 4, 6]
