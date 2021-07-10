/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Trap Rain
int Solution::trap(const vector<int> &A) {
    int n = A.size();
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    // Build left max
    leftMax[0] = A[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], A[i]);

    // Build right max
    rightMax[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], A[i]);

    int res = 0;
    for (int i = 1; i < n - 1; i++)
        res += max(min(leftMax[i], rightMax[i]) - A[i], 0);

    return res;
}
