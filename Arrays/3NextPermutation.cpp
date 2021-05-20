// Change the array to be the next permutation
// Time Complexity - O(N)
// Space Complexity - O(1)
void nextPermutation(vector<int> &nums) {
	// Find the element which is not in trend
	int i = n - 2;
	while (i >= 0 and nums[i] >= nums[i + 1])
		i--;

	// If it is not the last possible permutation
	if (i >= 0) {
		int j = n - 1;
		while (j >= 0 and nums[j] <= nums[i])
			j--;

		swap(nums[i], nums[j]);
	}

	// Reverse everything leaving the element not in trend.
	reverse(nums.begin() + (i + 1), nums.end());
	return;
}