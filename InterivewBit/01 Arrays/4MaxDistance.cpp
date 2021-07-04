/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find max (j - i) for A[i] <= A[j]
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    int res = 0;
    vector<pair<int, int>> nums;

    for (int i = 0; i < n; i++) {
        nums.push_back({A[i], i});
    }

    sort(nums.begin(), nums.end());

    // Make a suffix max array with indexes
    vector<int> maxLeft(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        maxLeft[i] = max(maxLeft[i + 1], nums[i].second);
    }

    // Find the max j - i for each element
    for (int i = 0; i < n; i++) {
        res = max(res, maxLeft[i] - nums[i].second);
    }

    return res;
}
