/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Count number of bits that are different in pairs
int Solution::cntBits(vector<int> &A) {
    int res = 0;
    int mod = 1e9 + 7;
    int n = A.size();

    vector<long long> ones(32, 0);
    vector<long long> zeros(32, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 31; j >= 0; j--) {
            if (A[i] & (1 << j))
                ones[j]++;
            else
                zeros[j]++;
        }
    }

    for (int i = 0; i <= 31; i++)
        res = (res + ((ones[i] % mod * zeros[i] % mod) * 2) % mod) % mod;

    return res % mod;
}
