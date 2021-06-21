/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find pivot in rotated sorted array.

int searchPivotInRotatedArray(vector<int>& nums, int target) {
	int n = nums.size();

	// Edge
	if (n == 0)
		return -1;

	int start = 0, end = n - 1;

	// We will first find the pivot
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] > nums[end])
			start = mid + 1;
		else
			end = mid;
	}

	int pivot = start;
	return pivot;
}