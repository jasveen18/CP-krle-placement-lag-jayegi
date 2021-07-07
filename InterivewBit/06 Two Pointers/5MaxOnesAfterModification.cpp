/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a binary array A and a number B, we need to find length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int countZero = 0;
    int maxSize = 0;
    int l = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] == 0)
            countZero++;

        while (countZero > B) {
            if (A[l] == 0) countZero--;
            l++;
        }

        maxSize = max(maxSize, (i - l + 1));
    }

    return maxSize;
}
