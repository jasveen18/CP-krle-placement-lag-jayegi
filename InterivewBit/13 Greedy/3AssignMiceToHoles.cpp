/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Fill holes in min time.
int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();

    int res = INT_MIN;

    for (int i = 0; i < n; i++) {
        res = max(res, abs(B[i] - A[i]));
    }

    return res;
}
