/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Two Sum
vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> idx;
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int target = B - A[i];
        if (idx.find(target) != idx.end()) {
            return {idx[target], i + 1};
        }

        if (idx.find(A[i]) == idx.end())
            idx[A[i]] = i + 1;
    }

    return {};
}
