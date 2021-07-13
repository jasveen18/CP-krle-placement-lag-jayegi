/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a string A and integer B, remove all consecutive same characters that have length exactly B.
string Solution::solve(string A, int B) {
    string res = "";
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n - 1 and A[j] == A[j + 1]) {
            j++;
        }

        if (j - i + 1 == B) {
            i = j;
        } else {
            res += A[i];
        }
    }

    return res;
}
