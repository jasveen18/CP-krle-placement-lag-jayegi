vector<vector<int>> subsets_helper(vector<int> &nums, int index) {
	// Base Case
	if (index == nums.size())
		return {{}};

	// Recursive Case
	vector<vector<int>> temp;
	temp = subsets_helper(nums, index + 1);

	// Ultimate results
	vector<vector<int>> res;

	// Exclude wale
	res = temp;

	// Include wale
	for (int i = 0; i < temp.size(); i++) {
		temp[i].push_back(nums[index]);
		res.push_back(temp[i]);
	}

	return res;
}


