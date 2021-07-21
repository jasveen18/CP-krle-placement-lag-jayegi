/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

// Find i, j, k such that :
// max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0;

    int n1 = A.size(), n2 = B.size(), n3 = C.size();
    int res = INT_MAX;
    while (i < n1 and j < n2 and k < n3) {
        int curr = max(abs(A[i] - B[j]), max(abs(B[j] - C[k]), abs(C[k] - A[i])));
        res = min(res, curr);

        if (A[i] <= B[j] and A[i] <= C[k])
            i++;
        else if (B[j] <= A[i] and B[j] <= C[k])
            j++;
        else if (C[k] <= A[i] and C[k] <= B[j])
            k++;
    }

    return res;
}
