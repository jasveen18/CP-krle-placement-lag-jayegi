/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the contiguous subarray within an array, A of length N which has the largest sum.
int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int maxSoFar = A[0];
    int maxEnding = A[0];

    for (int i = 1; i < n; i++) {
        maxSoFar = max(maxSoFar + A[i], A[i]);
        maxEnding = max(maxEnding, maxSoFar);
    }

    return maxEnding;
}