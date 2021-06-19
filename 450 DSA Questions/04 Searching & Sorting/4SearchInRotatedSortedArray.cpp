/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Search element in rotated sorted array.
int searchInRotatedArray(vector<int>& nums, int target) {
	int size = nums.size();
	int start = 0, end = size - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (nums[mid] == target)
			return mid;

		// Now let's see where mid lies
		if (nums[mid] >= nums[start]) {
			// Two cases here, element lies on the left or the right of the partition
			if (nums[mid] >= target and nums[start] <= target)
				end = mid - 1;
			else
				start = mid + 1;
		} else if (nums[mid] < nums[start]) {
			if (nums[mid] <= target and target <= nums[end])
				start = mid + 1;
			else
				end = mid - 1;
		}
	}

	return -1;
}