/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the container with most water. min(A[i], A[j]) * (j - 1)
int Solution::maxArea(vector<int> &A) {
    int n = A.size();

    int i = 0, j = n - 1;
    int res = 0;
    while (i < j) {
        res = max(res, min(A[i], A[j]) * (j - i));

        if (A[i] < A[j])
            i++;
        else
            j--;
    }

    return res;
}
