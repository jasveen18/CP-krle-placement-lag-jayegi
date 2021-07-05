/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return 1 if a number exists which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.
int Solution::perfectPeak(vector<int> &A) {
    int n = A.size();
    if (n == 0)
        return 0;

    vector<int> maxLeft(n);
    vector<int> minRight(n);

    maxLeft[0] = A[0];
    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i - 1], A[i]);
    }

    minRight[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        minRight[i] = min(minRight[i + 1], A[i]);
    }

    for (int i = 1; i < n - 1; i++) {
        if (A[i] > maxLeft[i - 1] and A[i] < minRight[i + 1])
            return 1;
    }

    return 0;
}
