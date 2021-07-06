/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - You are given a string S, and you have to find all the amazing substrings of S.

// Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).
int Solution::solve(string A) {
    int countVowels = 0;
    int mod = 10003;
    int n = A.size();
    vector<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < n; i++) {
        // Check for vowel
        if (find(vowels.begin(), vowels.end(), A[i]) != vowels.end()) {
            countVowels += ((n - i) % mod);
        }
    }

    return countVowels % mod;
}
