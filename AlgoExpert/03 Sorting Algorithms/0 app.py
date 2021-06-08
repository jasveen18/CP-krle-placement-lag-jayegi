import random
import math
import time


def selectionSort(nums, n):
    numOfComparisons = 0

    for i in range(n):
        minElement = i
        for j in range(i+1, n):
            numOfComparisons += 1
            if nums[minElement] > nums[j]:
                minElement = j
        nums[minElement], nums[i] = nums[i], nums[minElement]
    
    return nums, numOfComparisons


def insertionSort(nums, n):
    numOfComparisons = 0

    for i in range(1, n):
        selectedElement = nums[i]
        j = i-1
        numOfComparisons += 1
        while j>=0 and selectedElement < nums[j]:
            numOfComparisons += 1
            nums[j+1] = nums[j]
            j-=1
        nums[j+1] = selectedElement

    return nums, numOfComparisons


def mergeSort(nums, n):
    numOfComparisons = 0
    
    if n > 1:
        # Split the array for recursive calls
        mid = n // 2
        left = nums[:mid]
        right = nums[mid:]

        leftSorted, leftComparisons = mergeSort(left, len(left))
        rightSorted, rightComparisons = mergeSort(right, len(right))
        numOfComparisons += leftComparisons + rightComparisons

        # Perform merge operation
        i = 0
        j = 0
        k = 0

        # Check left and right parts and merge in ascending order
        while i < len(left) and j < len(right):
            numOfComparisons += 1
            if leftSorted[i] < rightSorted[j]:
                nums[k] = leftSorted[i]
                i += 1
            elif leftSorted[i] >= rightSorted[j]:
                nums[k] = rightSorted[j]
                j += 1
            k += 1

        # Copy left over elements
        while i < len(left):
            numOfComparisons += 1
            nums[k] = leftSorted[i]
            i+=1
            k+=1
        
        while j < len(right):
            numOfComparisons += 1
            nums[k] = rightSorted[j]
            j+=1
            k+=1
    
    return nums, numOfComparisons


def quickSort(nums, n, left=0, right=None):
    if right == None:
        right = n - 1

    numOfComparisons = 0
    if left < right:
        partition, numOfComparisons = doPartition(nums, left, right)
        leftSorted, leftComparisons = quickSort(nums, n, left, partition - 1)
        rightSorted, rightComparisons = quickSort(nums, n, partition + 1, right)
        numOfComparisons += leftComparisons + rightComparisons
    
    return nums, numOfComparisons


def doPartition(nums, left, right):
    comparisonsHere = 0
    partition = left

    for i in range(left, right):
        comparisonsHere += 1
        if nums[i] < nums[right]:
            nums[i], nums[partition] = nums[partition], nums[i]
            partition += 1
    
    nums[partition], nums[right] = nums[right], nums[partition]
    return partition, comparisonsHere


def heapSort(nums, n):
    numOfComparisons = 0
    for i in range(n, -1, -1):
        heapifyList(nums, n, i)
        numOfComparisons += heapifyList(nums, i, 0)
    for i in range(n-1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]
        numOfComparisons += heapifyList(nums, i, 0)

    return nums, numOfComparisons


def heapifyList(nums, n, idx):
    comparisonsHere = 0
    largestIdx = idx

    left = 2*idx + 1
    right = 2*idx + 2

    if left < n and nums[idx] < nums[left]:
        largestIdx = left
    if right < n and nums[largestIdx] < nums[right]:
        largestIdx = right
    
    if largestIdx != idx:
        comparisonsHere += 1
        nums[idx], nums[largestIdx] = nums[largestIdx], nums[idx]
        comparisonsHere += heapifyList(nums, n, largestIdx)
    
    return comparisonsHere


# Function to sort a given array using bubble sort algorithm
def bubbleSort(nums, n):
    numOfComparisons = 0

    # Run the loop for n-1 times
    for i in range(0, n-1):
        # Do n-1 pairwise comparisons between adjacent elements
        for j in range(0, n-1):
            numOfComparisons += 1
            # If they are not in order, swap them
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
    
    return nums, numOfComparisons


def optimizedBubbleSort(nums, n):
    numOfComparisons = 0

    # Run the loop for n-1 times
    for i in range(0, n-1):
        # We will not counted the elements already present in correct place
        k = n-i-1
        for j in range(k):
            numOfComparisons += 1
            # If not in ascending order, swap
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j]
    
    return nums, numOfComparisons


def countingSort(nums, n):
    b = [-1 for _ in range(n)]
    numOfComparisons = 0

    for i in range(n):
        count = 0
        for j in range(n):
            numOfComparisons += 1
            if nums[i] < nums[j]:
                count += 1
        b[count] = nums[i]
    
    return b, numOfComparisons

def generalCountingSort(nums, n):
    n = len(nums)
    numOfComparisons = 0

    maxElement = max(nums)
    minElement = min(nums)
    rangeElements = maxElement - minElement + 1

    countList = [0 for _ in range(rangeElements)]
    resultList = [0 for _ in range(n)]

    for i in range(n):
        countList[nums[i] - minElement] += 1

    for i in range(1, len(countList)):
        countList[i] += countList[i-1]

    for i in range(n - 1, -1, -1):
        resultList[countList[nums[i] - minElement] - 1] = nums[i]
        countList[nums[i] - minElement] -= 1

    return resultList, numOfComparisons


def printMenu():
    print("[1] Selection Sort")
    print("[2] Insertion Sort")
    print("[3] Merge Sort")
    print("[4] Quick Sort")
    print("[5] Heap Sort")
    print("[6] Bubble Sort")
    print("[7] Optimal-Bubble Sort")
    print("[8] Counting Sort")
    print("[9] General-Counting Sort")


def singleAlgorithm():
    printMenu()
    
    # Take input
    choosenAlgorithm = int(input("Enter your choice (index): "))
    sizeOfInput = int(input("Enter the size (> 0) of array: "))

    # Generate randomized array
    nums = [random.randint(0, 100000) for _ in range(sizeOfInput)]

    # Print the desired output as per choice
    if choosenAlgorithm == 1:
        sortedNums, comparisons = selectionSort(nums, sizeOfInput)
        print("Number of comparisons taken for Selection sort: " + str(comparisons))
        print()
    elif choosenAlgorithm == 2:
        sortedNums, comparisons = insertionSort(nums, sizeOfInput)
        print("Number of comparisons taken for Insertion sort: " + str(comparisons))
        print()
    elif choosenAlgorithm == 3:
        sortedNums, comparisons = mergeSort(nums, sizeOfInput)
        print("Number of comparisons taken for Merge sort: " + str(comparisons))
        print()
    elif choosenAlgorithm == 4:
        sortedNums, comparisons = quickSort(nums, sizeOfInput)
        print("Number of comparisons taken for Quick sort: " + str(comparisons))
        print()
    elif choosenAlgorithm == 5:
        sortedNums, comparisons = heapSort(nums, sizeOfInput)
        print("Number of comparisons taken for Heap sort: " + str(comparisons))
        print()
    elif choosenAlgorithm == 6:
        sortedNums, comparisons = bubbleSort(nums, sizeOfInput)
        print("Number of comparisons taken for Bubble sort: " + str(comparisons))
        print()
    elif choosenAlgorithm == 7:
        sortedNums, comparisons = optimizedBubbleSort(nums, sizeOfInput)
        print("Number of comparisons taken for Optimized Bubble sort: " + str(comparisons))
        print()
    elif choosenAlgorithm == 8:
        sortedNums, comparisons = countingSort(nums, sizeOfInput)
        print("Number of comparisons taken for Counting sort: " + str(comparisons))
        print()
    elif choosenAlgorithm == 9:
        sortedNums, comparisons = generalCountingSort(nums, sizeOfInput)
        print("Number of comparisons taken for General-Counting sort: " + str(comparisons))
        print()
    else:
        print("Please enter a valid choice.")
    

def multipleAlgorithm():
    # Input
    sizeOfInput = int(input("Enter the size (> 0) of array: "))
    # Generate randomized array
    nums = [random.randint(0, 1000) for _ in range(sizeOfInput)]

    print("------------------------------------------------------------------")
    print("Sorting\t\t\tArray\t\tNum. of\t\tRun time")
    print("algorithm name\t\tsize\t\tComparisons\t(in ms.)")
    print("------------------------------------------------------------------")

    algorithms = ['selectionSort', 'insertionSort', 'mergeSort', 'quickSort', 'heapSort', 
                  'bubbleSort', 'optimizedBubbleSort', 'countingSort', 'generalCountingSort']

    for algo in algorithms:
        sortingAlgo = eval(algo)
        arrayToSort = [el for el in nums]

        startTime = time.time()
        _, comparisons = sortingAlgo(arrayToSort, sizeOfInput)
        endTime = time.time()
        timeElapsed = round((endTime - startTime) * 1000, 2)
        if(len(algo) > 16):
            print(f'{algo}\t{sizeOfInput}\t\t{comparisons}\t\t{timeElapsed}')
        else:
            print(f'{algo}\t\t{sizeOfInput}\t\t{comparisons}\t\t{timeElapsed}')
    print()


def main():
    # Interactive menu
    while(True):
        print("[1] Test an individal sorting algorithm.")
        print("[2] Test multiple sorting algorithms.")
        choice = int(input("Choice: "))
        if choice == 1:
            singleAlgorithm()
        elif choice == 2:
            multipleAlgorithm()
        else:
            break

if __name__ == "__main__":
    main()