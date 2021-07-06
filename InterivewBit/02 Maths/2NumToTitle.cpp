/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given num convert to corresponding excel title.
string Solution::convertToTitle(int A) {
    string res = "";

    while (A) {
        int dig = A % 26;

        if (dig == 0) {
            res += "Z";
            A--;
        }
        else res += (dig) + 'A' - 1;
        A /= 26;
    }

    reverse(res.begin(), res.end());
    return res;
}
