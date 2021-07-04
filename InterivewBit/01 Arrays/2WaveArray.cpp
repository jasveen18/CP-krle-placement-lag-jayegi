/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print in wave a[i] >= a[i+1] <= a[i+2]
vector<int> Solution::wave(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());

    for (int i = 0; i < n - 1; i += 2) {
        swap(A[i], A[i + 1]);
    }

    return A;
}
