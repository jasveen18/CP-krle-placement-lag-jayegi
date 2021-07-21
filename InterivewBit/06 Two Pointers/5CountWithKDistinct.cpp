/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Count the number of subarrays with K distinct integers
int atMostKTimes(vector<int> &A, int B) {
    unordered_map<int, int> count;
    int n = A.size();

    int i = 0, j = 0;
    int res = 0;

    while (j < n) {
        if (count[A[j]] == 0)
            B--;
        count[A[j]]++;

        if (B < 0) {
            while (B < 0) {
                count[A[i]]--;

                if (count[A[i]] == 0)
                    B++;
                i++;
            }
        }

        res += (j - i + 1);
        j++;
    }

    return res;
}


int Solution::solve(vector<int> &A, int B) {
    // Exactly(K) = AtMost(K) - AtMost(K-1) // Sliding window se atmost K ka answer aa jayega
    return atMostKTimes(A, B) - atMostKTimes(A, B - 1);
}
