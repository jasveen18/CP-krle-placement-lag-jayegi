/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Median of a row-sorted matrix.
// O(r * log C)
int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int minel = INT_MAX, maxel = INT_MIN;
    for (int i = 0; i < n; i++) {
        minel = min(minel, A[i][0]);
        maxel = max(maxel, A[i][m - 1]);
    }

    int medianIdx = (n * m + 1) / 2;
    while (minel < maxel) {
        int mid = minel + (maxel - minel) / 2;

        int smallerCount = 0;
        for (int i = 0; i < n; i++) {
            smallerCount += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }

        if (smallerCount < medianIdx)
            minel = mid + 1;
        else
            maxel = mid;
    }

    return minel;
}
