/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Maximal String
void permuteThisString(string &A, int B, string &ans) {
    if (B == 0) {
        ans = max(A, ans);
        return;
    }

    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap(A[i], A[j]);
            permuteThisString(A, B - 1, ans);

            // Backtrack
            swap(A[i], A[j]);
        }
    }

    return;
}


string Solution::solve(string A, int B) {
    string ans = A;
    permuteThisString(A, B, ans);
    return ans;
}
