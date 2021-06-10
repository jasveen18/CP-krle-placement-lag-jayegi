int partition(int arr[], int start, int end) {
	int pivot = arr[end];
	int i = start - 1;
	int j = start;

	for (j = start; j < end; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[end]);
	return i + 1;
}


void quickSort(int arr[], int start, int end = n - 1) {
	if (start >= end)
		return;

	int part = partition(arr, start, end);
	quickSort(arr, start, part - 1);
	quickSort(arr, part + 1, end);
}