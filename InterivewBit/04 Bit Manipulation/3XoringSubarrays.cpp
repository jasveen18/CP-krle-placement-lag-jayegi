/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - XOR all subarrays and the xor of those answers
int Solution::solve(vector<int> &A) {

    int n = A.size();

    if (n % 2 == 0)
        return 0;

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            res ^= A[i];
        }
    }

    return res;
}
