/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

// X divides A i.e. A % X = 0
// X and B are co-prime i.e. gcd(X, B) = 1
int GCD(int A, int B) {
    if (A < B)
        return GCD(B, A);

    if (B == 0)
        return A;

    return GCD(B, A % B);
}

int Solution::cpFact(int A, int B) {
    int g = GCD(A, B);
    if (g == 1)
        return A;

    while (g != 1) {
        A /= g;
        g = GCD(A, B);
    }

    return A;
}
