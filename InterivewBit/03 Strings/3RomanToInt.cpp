/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert Roman to Integer
int Solution::romanToInt(string A) {
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int i = 0;
    int ans = 0;
    while (i < A.size() - 1) {
        if (mp[A[i]] < mp[A[i + 1]]) {
            ans += mp[A[i + 1]] - mp[A[i]];
            i += 2;
        } else {
            ans += mp[A[i]];
            i++;
        }
    }

    // check for last digit
    if (i == A.size() - 1)
        ans += mp[A[i]];

    return ans;
}
