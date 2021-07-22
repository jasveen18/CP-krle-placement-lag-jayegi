/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - KMP Algo
vector<int> computerLPS(string pattern) {
    vector<int> lps(pattern.size(), 0);
    int idx = 0;

    for (int i = 1; i < pattern.size(); i++) {
        if (pattern[i] == pattern[idx]) {
            lps[i] = idx + 1;
            idx++; i++;
        } else {
            if (idx != 0) {
                idx = lps[idx - 1];
            } else {
                lps[idx] = 0;
                idx++;
            }
        }
    }

    return lps;
}

int Solution::strStr(const string A, const string B) {
    if (A.size() == 0 or B.size() == 0)
        return -1;

    // KMP kr de?
    // Steps:
    // 1. LPS array banao
    // 2. Find kro phir
    vector<int> lps = computerLPS(B);

    int i = 0, j = 0;
    while (i < A.size() and j < B.size()) {
        if (A[i] == B[j]) {
            i++; j++;
        }

        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return j == B.size() ? (i - B.size()) : -1;
}
