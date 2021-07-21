/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
int Solution::diffPossible(const vector<int> &A, int k) {
    unordered_map<int, int> idx;
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int target1 = k + A[i];
        int target2 = -k + A[i];

        if (idx.find(target1) != idx.end() or idx.find(target2) != idx.end())
            return 1;
        idx[A[i]]++;
    }

    return 0;
}
