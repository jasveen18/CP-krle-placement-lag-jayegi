/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a 3 x A board,  find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.
int Solution::solve(int A) {
    // pattern 1 -> 4 * 3 * 1 = 12 // c1 c2 c1 aisa pattern (repeat ho jayega)
    // pattern 2 -> 4 * 3 * 2 = 24 // c1 c2 c3 aisa pattern
    // Total for n = 1 -> 36

    int mod = 1e9 + 7;
    long long pat1 = 12;
    long long pat2 = 24;

    // 12 * 17 + 24 * 16
    for (int i = 1; i < A; i++) {
        long long x = pat1 * 7 + pat2 * 5;
        long long y = pat1 * 10 + pat2 * 11;

        pat1 = x % mod;
        pat2 = y % mod;
    }

    return (pat1 + pat2) % mod;
}
