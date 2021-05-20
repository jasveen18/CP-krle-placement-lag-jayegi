// https://leetcode.com/problems/find-the-duplicate-number/
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.

// I: [2,5,9,6,9,3,8,9,7,1]
// O: 9

// Approach 1 - Sort and then see if two adjacent are same.
// Time Complexity - O(N Log N)
// Space Complexity - O(1)
int findDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] == nums[i + 1])
			return nums[i];
	}

	return -1;
}























