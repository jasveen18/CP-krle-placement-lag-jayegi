/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Count set bits
int Solution::numSetBits(unsigned int A) {
    int count = 0;
    while (A) {
        count++;
        A &= (A - 1);
    }

    return count;
}
