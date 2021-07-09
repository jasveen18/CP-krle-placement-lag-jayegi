/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Atmost 2 can be there.
int Solution::removeDuplicates(vector<int> &A) {
    int p = 0;
    int n = A.size();

    if (n <= 2)
        return A.size();

    int i = 0;
    while (i < n - 2) {
        if (A[i] == A[i + 1] and A[i + 1] == A[i + 2])
            i++;
        else {
            swap(A[i++], A[p++]);
        }
    }

    swap(A[i++], A[p++]);
    swap(A[i++], A[p++]);

    A.erase(A.begin() + p, A.end());
    return A.size();
}
