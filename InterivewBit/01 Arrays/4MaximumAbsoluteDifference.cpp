/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - |A[i] - A[j]| + |i - j| ko maximise
int maxOfFour(int a, int b, int c, int d) {
    return max(max(max(a, b), c), d);
}

int Solution::maxArr(vector<int> &A) {
    // Now this has 4 cases -
    // A[i] - A[j] + i - j
    // A[i] - A[j] - i + j
    // -A[i] + A[j] + i - j
    // -A[i] + A[j] - i + j

    // Now I need to find the max of all these 4 cases.
    int n = A.size();
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;

    for (int i = 0; i < n; i++) {
        max1 = max(max1, A[i] + i);
        min1 = min(min1, A[i] + i);

        max2 = max(max2, A[i] - i);
        min2 = min(min2, A[i] - i);

        max3 = max(max3, -A[i] + i);
        min3 = min(max3, -A[i] + i);

        max4 = max(max4, -A[i] - i);
        min4 = min(max4, -A[i] - i);
    }

    return maxOfFour(max1 - min1, max2 - min2, max3 - min3, max4 - min4);
}



// Editorial -
int Solution::maxArr(vector<int> &A) {
    int ans = 0, n = A.size();

    int max1 = INT_MIN, max2 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < n; i++) {
        max1 = max(max1, A[i] + i);
        max2 = max(max2, A[i] - i);
        min1 = min(min1, A[i] + i);
        min2 = min(min2, A[i] - i);
    }
    ans = max(ans, max2 - min2);
    ans = max(ans, max1 - min1);
    return ans;
}