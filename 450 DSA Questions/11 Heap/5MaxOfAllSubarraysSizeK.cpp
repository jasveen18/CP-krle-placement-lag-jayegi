/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the max of all subarrays of size k
// First approach that comes into mind is sliding window by readint the problem statement.

// Sliding Window Approach -
// O(N) Time | O(N) Space

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	list<int> dq;
	vector<int> res;
	int i = 0, j = 0;

	// Start traversing
	while (j < nums.size()) {
		// Insert the element -
		// First remove all the element which are smaller than the curr element
		// as they won't contribute the answer now
		while (dq.size() > 0 and dq.back() < nums[j]) {
			dq.pop_back();
		}
		dq.push_back(nums[j]);

		// Now check for k size pahuche ya ni
		if (j - i + 1 < k) j++;
		else if (j - i + 1 == k) {
			// Answer front pe stored hoga.
			res.push_back(dq.front());

			// Now move the sliding window
			// Check if jisko nikal re hai wo dq pe hai kya?
			if (dq.front() == nums[i])
				dq.pop_front();

			i++; j++;
		}
	}

	return res;
}


// Priority Queue Approach -
// O(N Log K) time | O(K) space

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	priority_queue<pair<int, int>> pq;
	vector<int> res;

	for (int i = 0; i < k; i++)
		pq.push({nums[i], i});

	res.push_back(pq.top().first);


	for (int i = k; i < nums.size(); i++) {
		pq.push({nums[i], i});

		while (pq.top().second <= i - k)
			pq.pop();

		res.push_back(pq.top().first)
	}

	return res;
}