/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 945. Minimum Increment to Make Array Unique
int minIncrementForUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int res = 0, prev = 0;

	for (int i = 0; i < nums.size(); i++) {
		res += max(0, prev - nums[i]);
		prev = max(prev, nums[i]) + 1;
	}

	return res;
}