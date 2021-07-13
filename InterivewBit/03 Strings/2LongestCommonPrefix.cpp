/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Longest Common Prefix
string Solution::longestCommonPrefix(vector<string> &A) {
    string res = A[0];
    int n = A.size();

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (j < res.size() and j < A[i].size() and res[j] == A[i][j]) {
            j++;
        }

        res = res.substr(0, j);
    }

    return res;
}
