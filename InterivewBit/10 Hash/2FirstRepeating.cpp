/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find first repeating number
int Solution::solve(vector<int> &A) {
    unordered_set<int> seen;
    int dup = -1;

    for (int i = A.size() - 1; i >= 0; i--) {
        if (seen.find(A[i]) != seen.end())
            dup = A[i];
        seen.insert(A[i]);
    }

    return dup;
}
