/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find Majority Element
int Solution::majorityElement(const vector<int> &A) {
    // Voting Algorithm
    int maxCountEl = A[0];
    int count = 1;
    int n = A.size();

    for (int i = 1; i < n; i++) {
        if (A[i] == maxCountEl) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            count = 1;
            maxCountEl = A[i];
        }
    }

    // Now check if this is correct or not, though considering constraints it is.
    // If you want to double check, count the number of occurances of maxCountEl, if it greater than (n/2), return that.
    return maxCountEl;
}
