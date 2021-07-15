/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.
int Solution::bulbs(vector<int> &A) {
    int countSwitched = 0;
    int n = A.size();

    for (int i = 0; i < n; i++) {
        if (countSwitched & 1) {
            A[i] = !A[i];
        }

        if (A[i] == 0) {
            countSwitched++;
        }
    }

    return countSwitched;
}
