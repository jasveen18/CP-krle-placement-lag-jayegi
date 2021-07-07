/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find pair with given difference
int binarySearch(vector<int> &arr, int target, int idx) {
    auto ans = upper_bound(arr.begin(), arr.end(), target);
    if (*prev(ans) != target or (ans - arr.begin() - 1) == idx)
        return -1;
    else
        return ans - arr.begin() - 1;
}

int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int curr = A[i];
        int required = B + A[i];

        if (binarySearch(A, required, i) != -1) {
            return 1;
        }
    }

    return 0;
}
