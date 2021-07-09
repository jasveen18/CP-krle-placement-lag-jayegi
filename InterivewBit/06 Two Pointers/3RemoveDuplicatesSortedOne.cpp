/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Remove Dups from sorted array. O(1)Space
int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();

    if (n == 1)
        return A.size();

    int p1 = 0;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] != A[i + 1]) {
            swap(A[i], A[p1]);
            p1++;
        }
    }
    swap(A[n - 1], A[p1]);

    A.erase(A.begin() + p1 + 1, A.end());
    return A.size();
}
