/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse Digits
int Solution::reverse(int A) {
    int sign = A < 0 ? 1 : 0;
    int n = abs(A);

    long long int res = 0;
    int multiplier = 10;

    while (n) {
        res *= 10;
        res += (n % 10);
        n /= 10;
    }

    if (res > INT_MAX)
        return 0;

    if (sign)
        return -res;
    return res;
}
