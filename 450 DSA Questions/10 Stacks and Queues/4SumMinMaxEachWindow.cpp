/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the sum of (min + max) for each subarray of window size = k
int sumMinMaxWindowK(vector<int> &nums, int k) {
	int n = nums.size();
	list<int> maxDq, minDq;

	int i = 0, j = 0, ans = 0;

	while (j < n) {
		// Empty the elements smaller than the curr from dq for max
		while (maxDq.empty() == false and maxDq.back() < nums[i])
			maxDq.pop_back();
		maxDq.push_back(nums[i]);

		// Empty the elements larger than the curr from dq for min
		while (minDq.empty() == false and minDq.back() > nums[i])
			minDq.pop_back();
		minDq.push_back(nums[i]);


		if (j - i + 1 < k)
			j++;
		else if (j - i + 1 == k) {
			// Do the calculation
			ans += (maxDq.front() + minDq.front());

			// Slide the window
			if (maxDq.front() == nums[i])
				maxDq.pop_front();
			if (minDq.front() == nums[i])
				minDq.pop_front();

			i++; j++;
		}
	}

	return ans;
}