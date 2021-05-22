// Approach 1 - 2 pointers, count till n
// Time Complexity - O(N)
// Space Complexity - O(1)
int medianOf2SortedArraySameSize(vector<int> &arr1, vector<int> &arr2) {
	// Size is be same for both
	int n = arr1.size();
	int count = 0;

	// Two pointers
	int p1 = 0, p2 = 0;
	// Since the number of elements will 2*n, there will be 2 medians
	int m1 = -1, m2 = -1;

	// Traverse till mid of "merged" array.
	for (count = 0; count <= n; count++) {
		// Check for end of the array
		if (p1 == n) {
			m1 = m2;
			m2 = arr2[0];
			break;
		}

		if (p2 == n) {
			m1 = m2;
			m2 = arr1[0];
			break;
		}

		// Go for the element whichever is smaller
		if (arr1[p1] <= arr2[p2]) {
			m1 = m2;
			m2 = arr1[p1++];
		} else {
			m1 = m2;
			m2 = arr2[p2++];
		}
	}

	return (m1 + m2) / 2;
}


// Approach 2** - Eliminating search space
// - Take the median of both arrays
// - Compare them, if they both are equal then return m1 or m2
// - if m1 < m2, then the median lie between arr1[m1, ...] and arr2[..., m2]
// - if m1 > m2, then the median lie between arr2[m2, ...] and arr1[..., m1]
// Repeat till both arrays have size 2.
// median = (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2

// Time Complexity - O(Log N)
// Space Complexity - O(1)

// Median of one array
int median(int arr[], int n) {
	if (n % 2 == 0)
		return (arr[n / 2] + arr[n / 2 - 1]) / 2;
	else
		return arr[n / 2];
}

// Median of two array
int getMedian(int arr1[], int arr2[], int n) {
	// Base Cases
	if (n == 1)
		return (arr1[0] + arr2[0]) / 2;
	if (n == 2)
		return (max(arr1[0], arr2[0]) + min(arr1[1], arr1[1])) / 2;

	// Median of both arrays
	int m1 = median(arr1, n);
	int m2 = median(arr2, n);

	if (m1 == m2)
		return m1;

	if (m1 < m2) {
		if (n % 2 == 0)
			return getMedian(arr1 + n / 2 - 1, arr2, n - n / 2 + 1);
		else
			return getMedian(arr1 + n / 2, arr2, n - n / 2);
	} else {
		if (n % 2 == 0)
			return getMedian(arr2 + n / 2 - 1, arr1, n - n / 2 + 1);
		else
			return getMedian(arr2 + n / 2, arr1, n - n / 2);
	}

}
