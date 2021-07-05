/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find smallest number having same digits but larger.
string Solution::solve(string A) {
    // This is same as next permutation only
    int n = A.size();
    int i = n - 2;

    while (i >= 0 and A[i] >= A[i + 1])
        i--;

    if (i == -1)
        return "-1";

    // If i is not -1, then there exists a next permutation
    int j = n - 1;
    while (j >= 0 and A[j] <= A[i])
        j--;
    swap(A[i], A[j]);

    reverse(A.begin() + i + 1, A.end());
    return A;
}
