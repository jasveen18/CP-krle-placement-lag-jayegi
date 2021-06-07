// Approach - Use a hashmap to store the prefix sum, if sum is already present,
//            means that that part of subarray sums to zero.
// Time Complexity - O(N)
// Space Complexity - O(N)
bool subArrayExists(int arr[], int n) {
    // Prefix sum
    unordered_map<int, int> prefixSum;
    int runningSum = 0;

    // Zero at the beginning
    prefixSum[runningSum] = 1;

    for (int i = 0; i < n; i++) {
        runningSum += arr[i];

        // If the sum was already present, then return true
        if (prefixSum.find(runningSum) == prefixSum.end()) {
            prefixSum[(runningSum)] = 1;
        } else {
            return true;
        }
    }

    // False, as there were no hits.
    return false;
}