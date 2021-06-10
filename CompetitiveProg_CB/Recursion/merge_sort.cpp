void merge(int arr, int start, int end) {
	int mid = start + (end - start) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;

	int temp[100];

	while (i <= mid and j <= e) {
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= e)
		temp[k++] = arr[j++];

	for (int i = start; i <= end; i++)
		arr[i] = temp[i];
}


void mergeSort(int arr[], int start, int end) {
	if (start >= end)
		return;

	// 3 step process.
	// 1. Divide
	int mid = start + (end - start) / 2;

	// 2. Sort the divided array recursively.
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	// 3. Merge both the arrays.
	merge(arr, start, end);
}