/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - You have to find the number of substrings in A which starts with vowel and end with consonants or vice-versa.
int Solution::solve(string A) {
    int mod = 1e9 + 7;
    int n = A.size();
    vector<int> vowels(n, 0);
    vector<int> consonants(n, 0);

    vowels[n - 1] = A[n - 1] == 'a' or A[n - 1] == 'e' or A[n - 1] == 'i' or A[n - 1] == 'o' or A[n - 1] == 'u';
    consonants[n - 1] = A[n - 1] != 'a' and A[n - 1] != 'e' and A[n - 1] != 'i' and A[n - 1] != 'o' and A[n - 1] != 'u';
    for (int i = n - 2; i >= 0; i--) {
        vowels[i] = vowels[i + 1] + (A[i] == 'a' or A[i] == 'e' or A[i] == 'i' or A[i] == 'o' or A[i] == 'u');
        consonants[i] = consonants[i + 1] + (A[i] != 'a' and A[i] != 'e' and A[i] != 'i' and A[i] != 'o' and A[i] != 'u');
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        if ((A[i] == 'a' or A[i] == 'e' or A[i] == 'i' or A[i] == 'o' or A[i] == 'u')) {
            res += (consonants[i]) % mod;
        } else {
            res += (vowels[i]) % mod;
        }
    }

    return res % mod;
}
