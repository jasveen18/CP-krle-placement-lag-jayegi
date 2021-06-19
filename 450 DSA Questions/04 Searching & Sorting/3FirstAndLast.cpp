/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find first and last element in a given sorted array.
// Use BS.

// T - O(Log N) | S - O(1)
vector<int> findFirstLast(int arr[], int n, int x) {
	int start = 0, end = n - 1;
	int firstIdx = -1, lastIdx = -1;

	// Find first
	while (start <= end) {
		int mid = (start + end) / 2;

		// Check
		if (arr[mid] > x) {
			end = mid - 1;
		} else if (arr[mid] < x) {
			start = mid + 1;
		} else {		// Element found
			firstIdx = mid;
			end = mid - 1;
		}
	}

	start = 0, end = n - 1;
	// Find last
	while (start <= end) {
		int mid = (start + end) / 2;

		// Check
		if (arr[mid] > x) {
			end = mid - 1;
		} else if (arr[mid] < x) {
			start = mid + 1;
		} else {		// Element found
			lastIdx = mid;
			start = mid + 1;
		}
	}

	return {firstIdx, lastIdx};
}