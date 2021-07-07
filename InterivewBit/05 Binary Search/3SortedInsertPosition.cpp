/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Insert the element at correct position
int Solution::searchInsert(vector<int> &A, int B) {
    int start = 0;
    int end = A.size();
    int idx = -1;

    while (start < end) {
        int mid = start + (end - start) / 2;
        if (A[mid] == B)
            return mid;

        if (A[mid] > B) {
            end--;
        } else {
            idx = mid;
            start = mid + 1;
        }
    }

    return idx + 1;
}
