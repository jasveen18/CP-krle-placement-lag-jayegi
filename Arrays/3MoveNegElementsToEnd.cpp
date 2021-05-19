// Approach 1 - Using 2 pointers
// Time Complexity - O(N)
// Space Complexity - O(1)
void moveNegNumToStart(vector<int> &nums) {
	int n = nums.size();

	int low = 0, high = n - 1;
	while (low < high) {
		while (nums[low] < 0 and low < high)
			low++;

		while (nums[high] >= 0 and low < high)
			high--;

		if (nums[low] >= 0 and nums[high] < 0) {
			swap(nums[low], nums[high]);
			low++, high--;
		}
	}
}