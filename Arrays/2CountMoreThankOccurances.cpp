// Time Complexity - O(N)
// Space Complexity - O(N)
int countOccurence(int arr[], int n, int k) {
    unordered_map<int, int> countEl;
    int ans = 0;
    int threshold = n / k;

    // Make the count data
    for (int i = 0; i < n; i++) {
        countEl[arr[i]]++;
    }

    // Check the elements which are above threshold
    for (auto el : countEl) {
        if (el.second > threshold)
            ans++;
    }

    return ans;
}