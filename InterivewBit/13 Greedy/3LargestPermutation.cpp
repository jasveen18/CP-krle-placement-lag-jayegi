/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Largest Permutation, at most k swaps
vector<int> Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> idx;
    for (int i = 0; i < n; i++) {
        idx[A[i]] = i;
    }

    int val = n;

    if (B >= 1e6) {
        for (int i = 0; i < n; i++) {
            A[i] = val--;
        }

        return A;
    }

    for (int i = 0; i < n and B; i++) {
        if (A[i] == n - i)
            continue;

        int temp = idx[n - i];

        idx[n - i] = idx[A[i]];
        idx[A[i]] = temp;

        swap(A[temp], A[i]);
        B--;
    }

    return A;
}