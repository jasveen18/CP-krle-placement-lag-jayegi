/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Divide Integers
int Solution::divide(int A, int B) {

    long long n = A, m = B;

    if (A == INT_MIN and B == -1)
        return INT_MAX;
    if (A == INT_MIN and B == 1)
        return INT_MIN;

    // Sign positive if both have same signs
    int sign = (n < 0) ^ (m < 0) ? -1 : 1;
    n = n == INT_MIN ? INT_MAX : abs(n);
    m = m == INT_MIN ? INT_MAX : abs(m);

    long long q = 0, t = 0;

    for (int i = 31; i >= 0; i--) {
        if (t + (m << i) <= n) {
            t += m << i;
            q = q | (1 << i);
        }

    }

    if (sign < 0) q = -q;
    return (q >= INT_MAX or q <= INT_MIN) ? INT_MAX : q;
}
