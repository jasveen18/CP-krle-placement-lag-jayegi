/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Len of last word.
int Solution::lengthOfLastWord(const string s) {
    string word = "";
    string lastWord;
    int n = s.size();

    // Remove the space from behind
    int end = n - 1;
    while (end >= 0 and s[end] == ' ')
        end--;

    for (int i = 0; i <= end; i++) {
        // Remove any extra space
        while (i < n and s[i] == ' ' and s[i + 1] == ' ')
            i++;

        if (s[i] == ' ') {
            lastWord = word;
            word = "";
        } else {
            word += s[i];
        }
    }

    lastWord = word;

    return lastWord.size();
}
