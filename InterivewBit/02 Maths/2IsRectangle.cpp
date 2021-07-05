/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if rectangle or not.
int Solution::solve(int A, int B, int C, int D) {

    if (((A == B) && (C == D)) || ((A == C) && (B == D)) || ((A == D) && (B == C))) {
        return 1;
    }

    return 0;
}