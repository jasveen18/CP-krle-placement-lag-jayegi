/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Large Fib (10 ^ 9).
long long fibRecursive(long long n, unordered_map<int, int> &dp, int &mod) {
    // Look up the dp
    if (dp.find(n) != dp.end()) return dp[n];

    long long k = (n / 2);
    if (n % 2 == 0) {
        return dp[n] = ((fibRecursive(k - 1, dp, mod) * fibRecursive(k - 1, dp, mod)) % mod + (fibRecursive(k, dp, mod) * fibRecursive(k, dp, mod)) % mod) % mod;
    } else {
        return dp[n] = ((fibRecursive(k, dp, mod) * fibRecursive(k + 1, dp, mod)) % mod + (fibRecursive(k, dp, mod) * fibRecursive(k - 1, dp, mod)) % mod) % mod;
    }
}

int Solution::solve(int A) {
    // I need to find the Nth Fib.
    // One of the approaches that I can think of is to use matrix exponentiation for fib numbers
    // T * A(n-1) = F(N)
    // where T = [[1, 0],[1, 1]].

    // There is one more approach that uses formulas and Dp.
    int mod = 1e9 + 7;
    unordered_map<int, int> dp;
    dp[0] = 1;
    dp[1] = 1;

    if (A == 0)
        return 0;

    return fibRecursive(A - 1, dp, mod) % mod;
}
