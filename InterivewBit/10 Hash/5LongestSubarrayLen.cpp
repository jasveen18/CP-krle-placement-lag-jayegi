/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given an integer array A of size N containing 0's and 1's only.

// You need to find the length of the longest subarray having count of 1’s one more than count of 0’s.
int Solution::solve(vector<int> &A) {
    int sum = 0;
    int n = A.size();

    unordered_map<int, int> idx;
    int res = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i] == 0 ? -1 : 1;

        // If sum == 1, means count of 1 is more jtoh update the res
        if (sum == 1)
            res = i + 1;

        // If this sum with index is not present, then add to hash table
        if (idx.find(sum) == idx.end())
            idx[sum] = i;

        // If (sum-1) already hai, means ki one exists at a place
        if (idx.find(sum - 1) != idx.end())
            res = max(res, i - idx[sum - 1]);
    }

    return res;
}
