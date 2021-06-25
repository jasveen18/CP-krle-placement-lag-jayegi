// Why is Merge Sort preferred for Linked Lists and Quick Sort preferred for Arrays?

// Arrays -
// 1. Quick Sort takes O(1) space while Merge Sort takes O(N) space. Allocating and deallocating the extra space increases the run time.
// 2. Both have same average time complexity, but merge sort has greater constant for arrays.
// 3. Quick Sort is a cache friendly algorithm and a randomized version works very well in practice.
// 4. it is tail recursive.

// Linked Lists -
// 1. Linked Lists doesn't require extra space in case of merge sort.
// 2. We can insert, deleted, or break the linked list in O(1) space.
// 3. For randomized quick sort, we need a random access data structure, which is not possible in linked list.
// 4. Quick sort needs traversal from both sides.