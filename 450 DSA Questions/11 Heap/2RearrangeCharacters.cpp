/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Rearrange characters in a string.
int rearrangeCharacters(string s) {
    int n = s.size();
    unordered_map<char, int> count;

    for (int i = 0; i < n; i++) {
        count[s[i]]++;

        if (count[s[i]] > (n / 2))
            return 0;
    }

    return 1;
}