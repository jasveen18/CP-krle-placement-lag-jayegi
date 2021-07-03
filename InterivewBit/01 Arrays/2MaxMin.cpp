/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the sum of max and min.
// Take min number of comparisons.
// We can further optimize to use only one function for both max and min.

int findMax(vector<int> &A, int start, int end) {
    if (start > end)
        return INT_MIN;

    // Base Case - single element
    if (start == end)
        return A[start];

    int mid = (start + end) / 2;
    int leftSide = findMax(A, start, mid);
    int rightSide = findMax(A, mid + 1, end);

    return max(leftSide, rightSide);
}

int findMin(vector<int> &A, int start, int end) {
    if (start > end)
        return INT_MAX;

    // Base Case - single element
    if (start == end)
        return A[start];

    int mid = (start + end) / 2;
    int leftSide = findMin(A, start, mid);
    int rightSide = findMin(A, mid + 1, end);

    return min(leftSide, rightSide);
}

int Solution::solve(vector<int> &A) {
    int maxNum = findMax(A, 0, A.size() - 1);
    int minNum = findMin(A, 0, A.size() - 1);

    return maxNum + minNum;
}
