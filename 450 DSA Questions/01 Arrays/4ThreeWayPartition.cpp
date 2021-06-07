// Approach - Use quick sort partition algo to rearrange
// Time Complexity - O(N)
// Space Complexity - O(1)
void threeWayPartition(vector<int>& array, int a, int b) {
	int partitionIndex = 0;
	int pivotEl = a;
	int n = array.size();

	for (int i = 0; i < n; i++) {
		if (array[i] < pivotEl) {
			swap(array[i], array[partitionIndex]);
			partitionIndex++;
		}
	}

	pivotEl = b;
	for (int i = partitionIndex; i < n; i++) {
		if (array[i] <= pivotEl) {
			swap(array[i], array[partitionIndex]);
			partitionIndex++;
		}
	}

	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << array.size() << endl;
	return;
}