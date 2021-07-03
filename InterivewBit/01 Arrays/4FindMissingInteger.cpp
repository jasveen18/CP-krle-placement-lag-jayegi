int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();

    // Convert the negative numbers and numbers > n+1 to zero as they don't contribute
    for (int i = 0; i < n; i++)
        if (A[i] < 0 or A[i] > n + 1)
            A[i] = 0;

    // Define a mod size to treat the array as a bucket count.
    int modSize = A.size() + 1;

    for (int i = 0; i < n; i++) {
        // Handle the zero case, mod se increase kr do
        if (A[i] % modSize == 0) {
            A[i] += modSize;
        }

        // Here, we are incrementing the numbers we found.
        else {
            int idx = A[i] % modSize;
            A[idx - 1] += modSize;
        }
    }

    // Find the first missing number
    int missingNum = A.size();

    for (int i = 0; i < n; i++) {
        if (A[i] <= modSize) {
            missingNum = i;
            break;
        }
    }

    // Return +1 as one based index
    return missingNum + 1;
}
