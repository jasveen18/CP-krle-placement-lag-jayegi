// Approach 1 - Sort the array and then arrange
// Note: Loses the initial sequence of array
// Time Complexity - O(N * Log N)
// Space Complexity - O(1)
void rearrangeArr(int arr[], int n) {
	// Sort the array
	sort(arr, arr + n);

	// Get the count of element
	int countPos = 0, countNeg = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0)
			countNeg++;
		else
			countPos++;
	}

	// Take care of positive positions
	int start = 1, end = n - 1;
	while (start <= 2 * min(countPos, countNeg)) {
		if (arr[start] < 0) {
			swap(arr[start], arr[end]);
		}
		start += 2;
	}

	// Take care of negative positions
	start = 0;
	while (start <= 2 * min(countPos, countNeg)) {
		if (arr[start] > 0) {
			swap(arr[start], arr[end]);
		}
		start += 2;
	}

	return;
}