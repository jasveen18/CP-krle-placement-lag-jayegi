/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given, A first number, C the common diff, tell if B is in AP or not.

int inSequence(int A, int B, int C) {
    int multi = B - A;

    if (C == 0)
        return A == B;

    if (C != 0 and multi % C != 0)
        return 0;

    if (C > 0)
        return B >= A;
    else
        return B <= A;
}