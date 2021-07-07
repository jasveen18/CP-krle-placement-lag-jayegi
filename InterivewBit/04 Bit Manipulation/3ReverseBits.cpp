/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse bits
unsigned int Solution::reverse(unsigned int A) {
    // 00000000000000000000000000000110
    // 01100000000000000000000000000000
    unsigned int res = 0;

    string bits = "";

    // Take the binary representation
    while (A) {
        bits += (A & 1) + '0';
        A = A >> 1;
    }

    // Add the left out digits
    while (bits.size() != 32) {
        bits += '0';
    }

    // Convert to number
    for (int i = 0; i < bits.size(); i++) {
        res *= 2;
        res += (bits[i] - '0');
    }

    return res;
}
