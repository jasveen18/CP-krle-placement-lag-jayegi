/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find number of trailing zeros in factorial.
int Solution::trailingZeroes(int A) {
    int mulitplier = 5;
    int ans = 0;
    while (A) {
        ans += (A / 5);
        A /= 5;
    }

    return ans;
}
