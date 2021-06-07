/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
* https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/
******************************************/

// T - O(N* N)
// S - O(1)
// Expand around center algorithm to find the palindrome at each index.
int expandAroundCenter(string s, int i, int j) {
    while (i >= 0 and j < s.size() and s[i] == s[j]) {
        i--; j++;
    }

    return j - i - 1;
}

// Expand around center
string longestPalin (string S) {
    if (S.size() == 1)
        return S;

    int longestPalinLen = 0;
    string longestPalin;

    int n = S.size();

    for (int i = 0; i < n - 1; i++) {
        // Odd length palin
        int oddMaxLen = expandAroundCenter(S, i, i);
        // Even length palin
        int evevMaxLen = expandAroundCenter(S, i, i + 1);
        // Max Len
        int maxLenAtI = max(oddMaxLen, evevMaxLen);

        // If new max is found, update
        if (maxLenAtI > longestPalinLen) {
            longestPalinLen = maxLenAtI;
            longestPalin = S.substr(i - ((maxLenAtI - 1) / 2), maxLenAtI);
        }
    }

    return longestPalin;
}