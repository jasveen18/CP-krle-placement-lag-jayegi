// Approach - Use a sliding window
// Time Complexity - O(N Log N)
// Space Complexity - O(1)
long long findMinDiff(vector<long long> a, long long n, long long m) {
    // Sort the array
    sort(a.begin(), a.end());

    long long minDif = LONG_MAX;

    // Use a sliding window to see which subarray is best
    for (int i = 0; i <= n - m; i++) {
        minDif = min(minDif, a[i + m - 1] - a[i]);
    }

    return minDif;
}