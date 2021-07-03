/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// BC 55

// 1. 1909 - Remove one element to make the array strictly increasing
bool canBeIncreasing(vector<int>& nums) {
	int n = nums.size();
	int lastSmallest = nums[0];
	int violations = 0;

	for (int i = 1; i < n; i++) {
		if (nums[i] <= lastSmallest) { // Not strictly increasing
			if (violations == 1)
				return false;

			violations++;

			// Update last smallest, we remove the element from i-1 position and take uske pehle wala solution
			if (i == 1 or nums[i] > nums[i - 2])
				lastSmallest = nums[i];
			// else remove the current element and leave last smallest as it is
		} else {
			lastSmallest = nums[i];
		}
	}

	return true;
}