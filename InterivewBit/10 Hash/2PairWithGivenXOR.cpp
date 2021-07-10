/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Count pairs with given xor.
int Solution::solve(vector<int> &A, int B) {

    int n = A.size();
    unordered_set<int> seen;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int target = B ^ A[i];
        if (seen.find(target) != seen.end()) {
            ans++;
        }

        seen.insert(A[i]);
    }

    return ans;
}
