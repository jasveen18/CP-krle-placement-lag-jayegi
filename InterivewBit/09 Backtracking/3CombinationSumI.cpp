/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the combinations to the target
void findTheCombinations(vector<int> &nums, int i, int &sum, vector<int> &curr, vector<vector<int>> &res, int k) {
    // Base Case
    if (i == nums.size()) {
        if (sum == k) {
            res.push_back(curr);
            return;
        } else {
            return;
        }
    }

    // Out of bound case - pruning
    if (sum > k)
        return;

    // Recursive Case
    // Exclude
    findTheCombinations(nums, i + 1, sum, curr, res, k);

    // Include
    curr.push_back(nums[i]);
    sum += nums[i];
    findTheCombinations(nums, i, sum, curr, res, k);

    // Backtrack
    curr.pop_back();
    sum -= nums[i];
    return;
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    int sum = 0;
    vector<int> curr;
    vector<vector<int>> res;

    findTheCombinations(A, 0, sum, curr, res, B);

    for (int i = 0; i < res.size(); i++)
        sort(res[i].begin(), res[i].end());

    sort(res.begin(), res.end());

    // Remove the duplicate items
    auto ip = unique(res.begin(), res.end());
    res.erase(ip, res.end());

    return res;
}
