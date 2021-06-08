# Count Sort
# Store the elements present in an hashmap, won't work for large numbers, for integers
# T - O(N)
# S - O(N)
def countSort(nums):
    minElement = int(min(nums))
    maxElement = int(max(nums))
    rangeOfElements = maxElement - minElement + 1

    # Initialize count list
    countList = [0 for _ in range(rangeOfElements)]

    # Store the count of every element present in nums
    for i in range(len(nums)):
        countList[nums[i] - minElement] += 1

    # Build the count list
    for i in range(1, len(countList)):
        countList[i] += countList[i-1]

    # Build the output list
    outputList = [0 for _ in range(len(nums))]
    for i in range(len(nums) - 1, -1, -1):
        outputList[countList[nums[i] - minElement] - 1] = nums[i]
        countList[nums[i] - minElement] -= 1

    for i in range(len(nums)):
        nums[i] = outputList[i]
    return nums


nums = [4, 6, 2, -1, -8, 0, 1, 3, 0]
print("Before Sorting: ")
print(nums)

countSort(nums)
print("After Sorting: ")
print(nums)

# Before Sorting:
# [4, 6, 2, -1, -8, 0, 1, 3, 0]
# After Sorting:
# [-8, -1, 0, 0, 1, 2, 3, 4, 6]
