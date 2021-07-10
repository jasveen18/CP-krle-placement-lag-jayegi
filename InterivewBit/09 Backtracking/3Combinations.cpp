/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find combinations of 'k' numbers
void makeCombinations(vector<int> &nums, int k, int i, vector<vector<int>> &res, vector<int> &curr) {
    // Base Case -
    if (k == 0) {
        res.push_back(curr);
        return;
    }

    if (i == nums.size()) {
        if (k == 0) {
            res.push_back(curr);
            return;
        } else
            return;
    }

    // Recursive Case -
    // Exclude
    makeCombinations(nums, k, i + 1, res, curr);

    // Include
    curr.push_back(nums[i]);
    makeCombinations(nums, k - 1, i + 1, res, curr);

    curr.pop_back();
    return;
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> nums;
    for (int i = 1; i <= A; i++) {
        nums.push_back(i);
    }

    vector<int> curr;
    vector<vector<int>> res;
    makeCombinations(nums, B, 0, res, curr);

    for (int i = 0; i < res.size(); i++)
        sort(res[i].begin(), res[i].end());
    sort(res.begin(), res.end());

    auto ip = unique(res.begin(), res.end());
    res.erase(ip, res.end());

    return res;
}
