/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find GCD
int Solution::gcd(int A, int B) {
    if (A < B)
        return gcd(B, A);

    if (B == 0)
        return A;

    return gcd(B, A % B);
}
