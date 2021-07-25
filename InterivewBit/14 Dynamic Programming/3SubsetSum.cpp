/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - If some subset has B as it's sum.
bool isPossible(vector<int> &nums, int idx, int k,  vector<vector<int>> &dp, int sum = 0) {
    if (sum == k)
        return dp[idx][sum] = 1;
    if (sum > k)
        return false;
    if (idx == nums.size())
        return dp[idx][sum] = 0;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    bool inc = isPossible(nums, idx + 1, k, dp, sum + nums[idx]);
    bool exc = isPossible(nums, idx + 1, k, dp, sum);

    return dp[idx][sum] = inc or exc;
}

int Solution::solve(vector<int> &A, int B) {
    int i = 0;
    vector<vector<int>> dp(A.size() + 1, vector<int> (B + 1, -1));

    return isPossible(A, i, B, dp);
}
