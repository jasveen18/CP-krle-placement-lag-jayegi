/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - find if there exists a pair of elements in the array whose difference is key.

bool binSearch(int arr[], int n, int key, int index) {
    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (mid != idx and arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}

bool findPair(int arr[], int n, int key) {
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        if (binSearch(arr, n, (key + arr[i]), i))
            return true;
    }

    return false;
}