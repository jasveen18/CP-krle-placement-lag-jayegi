int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);

    int minEl = arr[0];
    int maxEl = arr[n - 1];
    int minHeight = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] >= k) {
            minEl = min(arr[0] + k, arr[i] - k);
            maxEl = max(arr[i - 1] + k, arr[n - 1] - k);

            minHeight = min(minHeight, maxEl - minEl);
        }
    }

    return minHeight;
}