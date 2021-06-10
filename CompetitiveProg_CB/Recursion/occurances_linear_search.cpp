// First Occurance of a number.
int firstOcc (int arr[], int n, int key) {
	// Base Case
	if (n == 0)
		return -1;

	if (arr[0] == key)
		return 0;

	// Recursive Case
	int i = firstOcc(arr + 1, n - 1, key);

	// If element not found
	if (i == -1)
		return -1;

	// +1 to get the new index. We are solving the subproblem
	// [n] = [][n-1]
	return i + 1;
}


// Last Occurance of a number.
int lastOcc (int arr[], int n, int key) {
	// Base Case
	if (n == 0)
		return -1;

	// Recursive Case
	int i = lastOcc(arr + 1, n - 1, key);
	if (i == -1) {
		if (arr[0] == key)
			return 0;
		else
			return -1;
	}

	return i + 1;
}


// Find all occurances of a number.
void allOcc(int arr[], int n, int key, int i) {
	if (i == n)
		return;

	if (arr[i] == key)
		cout << i << ", ";

	allOcc(arr, n, key, i + 1);
}