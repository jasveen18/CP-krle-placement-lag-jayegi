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


// Approach 2 - Using a set (hashmap) to check if the element is already there.
// Time Complexity - O(N)
// Space Complexity - O(N)
int findDuplicate(vector<int> &nums) {
	set<int> elements;
	for (int i = 0; i < nums.size(); i++) {
		// If not present, add to set
		if (find(elements.begin(), elements.end(), nums[i]) == elements.end()) {
			elements.add(nums[i])
		} else { // If already present, this is the duplicate element
			return nums[i];
		}
	}
}


// Approach 3 - Floyd Warshall Algorithm
// Time Complexity - O(N)
// Space Complexity - O(1)
int findDuplicate(vector<int> &nums) {
	int tortoise = nums[0];
	int hare = nums[0];

	// Find the intersection point of two runners.
	while (tortoise != hare) {
		tortoise = nums[tortoise];
		hare = nums[nums[hare]];
	}

	// Find the start of the loop, that is our repeated element
	tortoise = nums[0];
	while (tortoise != hare) {
		tortoise = nums[tortoise];
		hare = nums[hare];
	}

	return hare;
}






















