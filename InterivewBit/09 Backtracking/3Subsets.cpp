/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find subsets
void findTheSubsets(vector<int> &nums, int i, vector<int> &curr, vector<vector<int>> &res) {
    // Base Case
    if (i == nums.size()) {
        res.push_back(curr);
        return;
    }

    // Recursive Case -
    // 1. Exclude this element
    findTheSubsets(nums, i + 1, curr, res);

    // Include this
    curr.push_back(nums[i]);
    findTheSubsets(nums, i + 1, curr, res);

    // Backtrack
    curr.pop_back();
    return;
}


vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> curr;

    findTheSubsets(A, 0, curr, res);

    for (int i = 0; i < res.size(); i++)
        sort(res[i].begin(), res[i].end());

    sort(res.begin(), res.end());
    return res;
}
