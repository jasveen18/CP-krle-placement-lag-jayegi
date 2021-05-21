// Time Complexity - O(N)
// Space Complexity - OO1)
int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> present;
    int pairs = 0;

    for (int i = 0; i < n; i++) {
        int target = k - arr[i];
        // Element found, add count of such elements.
        if (present.find(target) != present.end()) {
            pairs += present[target];
        }

        // Mark the current element as present
        present[arr[i]]++;
    }

    return pairs;
}