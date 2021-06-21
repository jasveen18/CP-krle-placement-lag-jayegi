/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Allocate Books
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#

bool isPossibleToDistribute(int arr[], int n, int m, int sep) {
    int students = 1, pagesRead = 0;

    for (int i = 0; i < n; i++) {
        // Should not exceed the pages required, usse pehle hi break kr do.
        if (pagesRead + arr[i] > sep) {
            students++;
            pagesRead = arr[i];

            // Exactly that much divisions required hai.
            if (students > m)
                return false;
        } else {
            pagesRead += arr[i];
        }
    }

    return true;
}

int findPages(int arr[], int n, int m) {
    // Binary Search Solution
    int sum = 0, maxx = -1;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxx = max(maxx, arr[i]);
    }

    // Search space
    int start = maxx;
    int end = sum;
    int ans = INT_MAX;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossibleToDistribute(arr, n, m, mid)) {
            ans = min(ans, mid);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if (ans == INT_MAX)
        return -1;
    return ans;
}