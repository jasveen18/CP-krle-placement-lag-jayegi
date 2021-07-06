/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find non-dup number.
int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        ans ^= A[i];
    }
    return ans;
}
