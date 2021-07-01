// *** Maximum of all subarrays of size k *** //

// Problem Statement -
// Given an array and size of window, k.
// We have to take all the subarray and find the max of each subarray and return it.
// return vector<int>

// Identification -
// 1. Array dia hai.
// 2. Subarray ki baatein hori hai.
// 3. Window size de rkha hai.


// Approach -
// Traverse the array and ek list bana lo
// Whenever you see a elemenent, usse chote walo ko hata do.
// And wo bada wala element will stay at front. Phir usse chote wale uske baad daalte rho.
// Now when sliding, if front == element jisko window se nikal re hai toh pop_front kr do.
vector<int> maxOfAllSubarrays(vector<int> &nums, int k) {
	vector<int> res;
	int size = nums.size();

	// Ek doubly ended queue, ya doubly linked list
	list<int> highestEl;

	if (k > size)
		return {*max_element(nums.begin(), nums.end())};

	int i = 0, j = 0;
	while (j < size) {
		// Do the insertion - iske jitne bhi smaller hai wo kaam ke ni hai, usko nikal do.
		while (highestEl.size() > 0 and highestEl.back() < nums[i]) {
			highestEl.pop_back();
		}
		highestEl.push_back(nums[j]);

		// If window size se chota hai
		if (j - i + 1 < k) {
			j++;
		} else if (j - i + 1 == k) {
			// Print the highest wala - highest ko hmesha front pe rakh re hai.
			res.push_back(highestEl.front());

			// Slide krte hai - agar present hoga toh aage hi hoga.
			if (highestEl.front() == nums[i]) {
				highestEl.pop_front();
			}

			i++; j++;
		}
	}

	return res;
}