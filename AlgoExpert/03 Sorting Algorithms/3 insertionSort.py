# Insertion sort
# Pick the element and put it into it's correct position on the left side of the array
# T - O(N*N)
# S - O(1)
def insertionSort(nums):
    # Start Loop
    for i in range(1, len(nums)):
        key = nums[i]

        # Put the elements at it's correct position
        j = i - 1
        while j >= 0 and key < nums[j]:
            nums[j+1] = nums[j]
            j -= 1
        nums[j+1] = key


nums = [4, 6, 2, -1, -8, 0, 1, 3, 0]
print("Before Sorting: ")
print(nums)

insertionSort(nums)
print("After Sorting: ")
print(nums)

# Before Sorting:
# [4, 6, 2, -1, -8, 0, 1, 3, 0]
# After Sorting:
# [-8, -1, 0, 0, 1, 2, 3, 4, 6]
