/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Trailing zeros
int Solution::solve(int A) {
    int ans = 0;
    while (!(A & 1)) {
        A = A >> 1;
        ans++;
    }

    return ans;
}
