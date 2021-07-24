/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min chars at end (same algo bss, rev + $ + A) krenge
int Solution::solve(string A) {
    string rev = A;
    reverse(rev.begin(), rev.end());

    string targetString = rev + '$' + A;

    // Now we need to calculate the LPS array such as in KMP Algorithm
    vector<int> lps(targetString.size(), 0);
    int idx = 0;

    // KMP Algo ka LPS hai
    for (int i = 1; i < targetString.size(); ) {
        if (targetString[i] == targetString[idx]) {
            lps[i] = idx + 1;
            idx++; i++;
        } else {
            if (idx != 0) {
                idx = lps[idx - 1];
            } else {
                lps[idx] = 0;
                i++;
            }
        }
    }

    return A.size() - lps[targetString.size() - 1];
}
