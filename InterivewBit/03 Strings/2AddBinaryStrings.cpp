/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Add two binary strings, return a binary string
string Solution::addBinary(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    string res = "";

    int carry = 0;
    for (int i = 0; i < max(A.size(), B.size()); i++) {
        int dig1 = i >= A.size() ? 0 : (A[i] - '0');
        int dig2 = i >= B.size() ? 0 : (B[i] - '0');

        int sumHere = (dig1 + dig2 + carry);
        res += (sumHere % 2) + '0';
        carry = sumHere / 2;
    }

    if (carry) {
        res += "1";
    }

    reverse(res.begin(), res.end());
    return res;
}
