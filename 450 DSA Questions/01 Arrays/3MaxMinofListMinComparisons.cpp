// Approach 1 - Do a linear search
void minMaxListLinear(vector<int> nums, int n) {
	int minNum = nums[0];
	int maxNum = nums[0];

	for (int i = 1; i < n; i++) {
		minNum = min(minNum, nums[i]);
		maxNum = max(maxNum, nums[i]);
	}

	cout << minNum << " " << maxNum;
}


// Approach 2 - Tournament Method (Divide and Conquer)
// [minNum, maxNum]
vector<int> minMaxListDnC(vector<int> nums, int low, int high) {
	// Base Case - if n = 1, both min and max will be first element
	if (low == high)
		return {nums[low], nums[low]};

	// If n = 2, return answer in one comparison
	if (high - 1 == low)
		return {min(nums[low], nums[high]), max(nums[low], nums[high])};

	// Recursive Case
	int mid = (low + high) / 2;
	vector<int> resLeft = minMaxListDnC(nums, low, mid);
	vector<int> resRight = minMaxListDnC(nums, mid + 1, high);
	vector<int> resHere = {nums[low], nums[low]};

	// Min and Max of current level
	resHere[0] = min3(resHere[0], resLeft[0], resRight[0]);
	resHere[1] = max3(resHere[1], resLeft[1], resRight[1]);

	return resHere;
}
