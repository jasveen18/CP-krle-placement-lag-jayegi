/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.
int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();

    for (int i = 0; i < n; i++) {
        // Skip duplicates
        while (i < n - 1 and A[i] == A[i + 1])
            i++;
        // If p exists
        if (A[i] == (n - i - 1))
            return 1;
    }

    return -1;
}
