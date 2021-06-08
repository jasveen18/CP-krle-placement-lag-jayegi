# Heap Sort
# Treats array like a binary tree and moves the largest values to end of the heap until sorted.
# T - O(N Log N)
# S - O(1)
def heapSort(nums):
    n = len(nums)

    # Build max heap
    for i in range(n//2-1, -1, -1):
        heapify(nums, n, i)

    # Extract elements one by one
    for i in range(n-1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]
        heapify(nums, i, 0)


def heapify(nums, n, i):
    largest = i     # Initilize largest as root
    l = 2*i + 1
    r = 2*i + 2

    # Check if left child of root exists, if yes, is it greater then root
    if l < n and nums[largest] < nums[l]:
        largest = l

    # Check if right child of root exists, if yes, is it greater than root
    if r < n and nums[largest] < nums[r]:
        largest = r

    # Change root if left or right was larger
    if largest != i:
        nums[i], nums[largest] = nums[largest], nums[i]     # Swap

        # Heapify the root
        heapify(nums, n, largest)


nums = [4, 6, 2, -1, -8, 0, 1, 3, 0]
print("Before Sorting: ")
print(nums)

heapSort(nums)
print("After Sorting: ")
print(nums)

# Before Sorting:
# [4, 6, 2, -1, -8, 0, 1, 3, 0]
# After Sorting:
# [-8, -1, 0, 0, 1, 2, 3, 4, 6]
