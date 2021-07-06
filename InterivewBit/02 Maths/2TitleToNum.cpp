/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert Excel Title to Columns
int Solution::titleToNumber(string A) {
    int res = 0;
    int multiplier = 1;
    int n = A.size();

    for (int i = n - 1; i >= 0; i--) {
        res += (A[i] - 'A' + 1) * multiplier;
        multiplier *= 26;
    }

    return res;
}
