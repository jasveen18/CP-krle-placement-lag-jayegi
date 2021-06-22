void mergeSortCount(long long arr[], long long start, long long end, long long int &count) {
	if (start < end) {
		long long int mid = (start + end) / 2;

		// Recursive function on two halves
		mergeSortCount(arr, start, mid, count);
		mergeSortCount(arr, mid + 1, end, count);

		// Merge Function
		long long i = 0, j = mid + 1, k = 0;
		long long space[5 * 100001] = {0};

		while (i <= mid and j <= end) {
			if (arr[i] > arr[j]) {
				// Itne log bade hai isme abhi.
				count += mid - i + 1;
				space[k++] = arr[j++];
			} else {
				space[k++] = arr[i++];
			}
		}

		// Add the left-over elements
		while (i <= mid) {
			space[k++] = arr[i++];
		}

		while (j <= end) {
			space[k++] = arr[j++];
		}

		for (int x = start; x <= end; x++) {
			arr[x] = space[x];
		}
	}

	return;
}


// Inversion count function to use merge sort to find count inversions
long long int inversionCount(long long arr[], long long N) {
	long long int countInv = 0;
	mergeSortCount(arr, 0, N - 1, countInv);
	return countInv;
}