/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Sort array with squares.
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();

    int firstNeg = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            firstNeg = i;
        }
    }
    int firstPos = firstNeg + 1;

    vector<int> res;
    while (firstNeg >= 0 and firstPos < n) {
        while (firstNeg >= 0 and abs(A[firstNeg]) <= A[firstPos]) {
            res.push_back(A[firstNeg] * A[firstNeg]);
            firstNeg--;
        }

        while (firstPos < n and abs(A[firstNeg]) > A[firstPos]) {
            res.push_back(A[firstPos] * A[firstPos]);
            firstPos++;
        }


    }

    while (firstNeg >= 0) {
        res.push_back(A[firstNeg] * A[firstNeg]);
        firstNeg--;
    }

    while (firstPos < n) {
        res.push_back(A[firstPos] * A[firstPos]);
        firstPos++;
    }

    return res;
}
