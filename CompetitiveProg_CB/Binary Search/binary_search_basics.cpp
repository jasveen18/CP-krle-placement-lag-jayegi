int binarySearch(int arr[], int n, int k) {
	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == k)
			return mid;
		if (arr[mid] > k)
			end = mid - 1;
		if (arr[mid] < k)
			start = mid + 1;
	}

	return -1;
}

// Lower Bound
int firstOccurance(int arr[], int n, int key) {
	int s = 0;
	int e = n - 1;

	int ans = -1;

	// Update in the direction that ans gets lower and lower.
	while (s <= e) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) {
			ans = mid;
			// Do not stop, explore the left part of array.
			e = mid - 1;
		}
		if (arr[mid] > key) {
			e = mid - 1;
		}
		if (arr[mid] < key) {
			s = mid + 1;
		}
	}

	return ans;
}

// Upper Bound
int lastOccurance(int arr[], int n, int key) {
	int s = 0;
	int e = n - 1;

	int ans = -1;

	// Update in the direction that ans gets higher and higher.
	while (s <= e) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) {
			ans = mid;
			// Do not stop, explore the right part of the array.
			s = mid + 1;
		}
		if (arr[mid] > key) {
			e = mid - 1;
		}
		if (arr[mid] < key) {
			s = mid + 1;
		}
	}

	return ans;
}