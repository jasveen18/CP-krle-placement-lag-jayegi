/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Search Range
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int startPos = -1, endPos = -1;

    int start = 0, end = A.size() - 1;

    while (start <= end) {
        int mid = (start) + (end - start) / 2;

        if (A[mid] == B) {
            startPos = mid;
            start = mid + 1;
        } else if (A[mid] < B) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    start = 0, end = A.size() - 1;
    while (start <= end) {
        int mid = (start) + (end - start) / 2;

        if (A[mid] == B) {
            endPos = mid;
            end = mid - 1;
        } else if (A[mid] < B) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return {endPos, startPos};

}
