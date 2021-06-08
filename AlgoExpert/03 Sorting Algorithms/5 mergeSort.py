# Merge sort
# Divide the array by half and then sort them while merging up.
# T - O(N * Log N)
# S - O(N) / O(1) depending on implementation.
def mergeSort(nums, size):
    # Else there is nothing to sort
    if size > 1:
        mid = size // 2
        leftHalf = nums[:mid]
        rightHalf = nums[mid:]

        # Recursive Function to sort both the parts
        leftSorted = mergeSort(leftHalf, len(leftHalf))
        rightSorted = mergeSort(rightHalf, len(rightHalf))

        # Merge both the halves while retaining the sorted properties
        i = 0
        j = 0
        k = 0

        # Check left and right parts and merge in ascending order
        while i < len(leftHalf) and j < len(rightHalf):
            if leftSorted[i] < rightSorted[j]:
                nums[k] = leftSorted[i]
                i += 1
            elif leftSorted[i] >= rightSorted[j]:
                nums[k] = rightSorted[j]
                j += 1
            k += 1

        # Copy left over elements
        while i < len(leftHalf):
            nums[k] = leftSorted[i]
            i += 1
            k += 1

        while j < len(rightHalf):
            nums[k] = rightSorted[j]
            j += 1
            k += 1

    return nums


nums = [4, 6, 2, -1, -8, 0, 1, 3, 0]
print("Before Sorting: ")
print(nums)

mergeSort(nums, len(nums))
print("After Sorting: ")
print(nums)

# Before Sorting:
# [4, 6, 2, -1, -8, 0, 1, 3, 0]
# After Sorting:
# [-8, -1, 0, 0, 1, 2, 3, 4, 6]
