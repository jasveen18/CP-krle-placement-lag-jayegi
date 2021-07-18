/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.


// Approach 1 - Your approach
// O(N) Time | O(N) Space
bool canJump(vector<int>& nums) {
    int n = nums.size();

    if (n <= 1)
        return true;

    // DP is your energy, suppose that each element is energy
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];

    if (dp[0] == 0)
        return false;

    // Not checking for last element since 2nd last tk energy hai toh pahuch hi jayenge
    for (int i = 1; i < n - 1; i++) {
        dp[i - 1]--;
        dp[i] = max(dp[i - 1], nums[i]);

        if (dp[i] <= 0)
            return false;
    }

    return true;
}


// Approach 2 - Check if we can reach the last index from current, same like sol1. but no extra space
// O(N) Time | O(1) Space
bool canJump(vector<int> &nums) {
    int distance = 0;

    // Till distance, as utna hi energy hai, we will even update it
    for (int i = 0; i <= distance; i++) {
        distance = max(distance, i + A[i]); // (i + A[i]) means mera reach from this index

        // Now, we can reach the last index and don't need to really iterate there
        if (distance >= nums.size() - 1)
            return true;
    }

    // Loop ended and we couldn't reach the last index
    return false;
}