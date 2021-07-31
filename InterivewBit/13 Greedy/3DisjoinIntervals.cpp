/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Count of disjoin intervals
bool sortEnd(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), sortEnd);

    int join = 0;
    int n = A.size();

    int end = A[0][1];

    for (int i = 1; i < n; i++) {
        if (A[i][0] <= end) {
            join++;
        } else {
            end = A[i][1];
        }
    }

    return n - join;
}
