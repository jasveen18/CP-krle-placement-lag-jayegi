/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find pair giving min value
int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int ans = INT_MAX;

    for (int i = 0; i < A.size() - 1; i++) {
        ans = min(ans, A[i] ^ A[i + 1]);
    }

    return ans;
}
