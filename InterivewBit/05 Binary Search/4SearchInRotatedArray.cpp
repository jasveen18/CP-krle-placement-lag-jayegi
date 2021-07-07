/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Search in rotated array
int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (A[mid] == B)
            return mid;

        // 2 Cases -
        // Case 1 - Mid lies in first array
        else if (A[mid] >= A[start]) {
            if (A[mid] >= B and B >= A[start])
                end = mid - 1;
            else
                start = mid + 1;
        }
        // Case 2 - Mid lies in second array
        else {
            if (A[mid] <= B and B <= A[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}
