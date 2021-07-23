/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Every number occurs thrice, except one.

//Approach 1 - O(32 *N) time, O(32) space
int Solution::singleNumber(const vector<int> &A) {
    vector<int> count(33, 0);
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int j = 0;
        int el = A[i];
        while (el) {
            if (el & 1)
                count[j]++;
            j++;
            el /= 2;
        }
    }

    int res = 0;
    for (int i = 0; i < 32; i++) {
        if (count[i] % 3 != 0) {
            res += pow(2, i);
        }
    }

    return res;
}



// Approach 2 - O(32 *N) time, O(1) space
int Solution::singleNumber(const vector<int> &A) {
    int count, ans = 0;

    for (int i = 0; i < 32; i++) {
        count = 0;
        // Count that bit for every number in this approach, then process
        for (int j = 0; j < A.size(); j++) if (1 << i & A[j]) count++;

        if (count % 3)
            ans = ans + pow(2, i);
    }
    return ans;
}