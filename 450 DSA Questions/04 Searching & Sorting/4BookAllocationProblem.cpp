/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -     //Function to find minimum number of pages.

// BS on solution space

bool isPossibleToAllocate(int arr[], int n, int m, int pages) {
	int allocations = 0;
	int runningSumPages = 0;
	int maxPossible = 0;

	for (int i = 0; i < n; i++) {
		runningSumPages += arr[i];
		if (runningSumPages >= pages) {
			allocations++;
			maxPossible = max(runningSumPages, maxPossible);
			runningSumPages = 0;
		}
	}

	return allocations >= m ? maxPossible : -1;
}

int findPages(int arr[], int n, int m) {
	sort(arr, arr + n);

	// Make the solution space - min will be max pages of a book, max will be sum of pages
	int start = *max_element(arr, arr + n);
	int end = accumulate(arr, arr + n, 0);
	int minPages = start;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		// Now try to allocate books with this number of pages
		int maxPagesAllocate = isPossibleToAllocate(arr, n, m, mid);
		if (maxPagesAllocate != -1) {
			minPages = min(minPages, maxPagesAllocate);
			end = mid - 1; // Now try to aim for smaller number
		} else { // Not able to allocate
			start = mid + 1;
		}
	}

	return minPages;
}
