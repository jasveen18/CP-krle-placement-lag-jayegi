// Bubble Sort Recursively
void bubbleSort(int *arr, int n) {
	// Base Case
	if (n == 1)
		return;

	// Recursive Case
	for (int j = 0; j < n - 1; j++) {
		if (arr[j] > arr[j + 1]) {
			swap(arr[j], arr[j + 1]);
		}
	}

	// Sort the n-1 elements after the largest element is at end.
	bubbleSort(arr, n - 1);
}


// Bubble Sort Recursive - Puraaa
void bubbleSortRecursive(int *arr, int j, int n) {
	// Base Case
	if (n == 1)
		return;

	// When single pass of the current array is done.
	if (j == n - 1)
		bubbleSortRecursive(arr, 0, n - 1);

	// Recursive Case
	if (arr[j] > arr[j + 1])
		swap(arr[j], arr[j + 1]);

	bubbleSortRecursive(arr, j + 1, n);
}