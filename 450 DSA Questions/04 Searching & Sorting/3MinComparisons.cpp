/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given three distinct numbers A, B and C. Find the number with value in middle (Try to do it with minimum comparisons).
int middle(int A, int B, int C) {
    // only 2 comparison
    int x = A - B;
    int y = B - C;
    int z = C - A;

    // Means ki x and y hold true, by true I mean A > B > C. Isliye '+'ve hai.
    if (x * y > 0)
        return B;

    // Means ki y and z hold true, B > C > A
    if (y * z > 0)
        return C;

    // Else B > A > C or C > A > B.
    return A;
}