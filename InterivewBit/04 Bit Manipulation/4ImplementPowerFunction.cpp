/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Power Function
int Solution::pow(int x, int n, int d) {
    if (x == 0)
        return x;

    if (n == 1)
        return (x + d) % d;

    long long int num = x;
    long long int res = 1;
    while (n) {
        if (n & 1) {
            res = ((res * num) + d) % d;
        }

        num = ((num * num) + d) % d;
        n >>= 1;
    }

    return (res + d) % d;
}
