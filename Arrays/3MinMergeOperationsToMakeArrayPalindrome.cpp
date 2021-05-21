// Approach - Merge the elements which are smaller
// Time Complexity - O(N)
// Space Complexity - O(1)
int findCountMerge(vector<int> arr) {
	int n = arr.size();

	int start = 0, end = n - 1;
	int operations = 0;

	while (start <= end) {
		// If both element are same
		if (arr[start] == arr[end]) {
			start++; end--;
		} else if (arr[start] > arr[end]) {
			end--;
			arr[end] += arr[end + 1];
			operations++;
		} else {
			start++;
			arr[start] += arr[start - 1];
			operations++;
		}
	}

	return operations;
}