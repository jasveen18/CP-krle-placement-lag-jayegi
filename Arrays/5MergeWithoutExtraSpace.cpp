// Merge without using any extra space
// Time Complexity - O((n+m)*log(n+m))
// Space Complexity - O(1)

// Kinda modified Ceil
int nextGap(int gap) {
    if (gap == 1 or gap == 0)
        return 0;
    else
        return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int arr2[], int n, int m) {
    int totalSize = n + m;

    // Kinda Shell Sort
    for (int gap = 0; gap < totalSize; gap = nextGap(gap)) {
        for (int i = 0; i < totalSize - gap; i++) {
            int j = i + gap;

            // Case 1: If both index lie in first arr
            if (i < n and j < n) {
                if (arr1[i] > arr1[j])
                    swap(arr1[i], arr1[j]);
            }

            // Case 2: If i in first arr and j in second arr
            else if (i < n and j > n) {
                if (arr1[i] > arr2[j - n])
                    swap(arr1[i], arr2[j - n]);
            }

            // Case 3: Both index lie in second arr
            else if (i > n and j > n) {
                if (arr2[i - n] > arr2[j - n])
                    swap(arr2[i - n], arr2[j - n]);
            }
        }
    }

    return;
}