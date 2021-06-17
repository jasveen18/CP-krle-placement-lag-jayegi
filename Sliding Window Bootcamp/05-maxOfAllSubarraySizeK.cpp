// *** Maximum of all subarrays of size k *** //

// Problem Statement -
// Given an array and size of window, k.
// We have to take all the subarray and find the max of each subarray and return it.
// return vector<int>

// Identification -
// 1. Array dia hai.
// 2. Subarray ki baatein hori hai.
// 3. Window size de rkha hai.

vector<int> maxOfAllSubarrays(vector<int> &nums, int k) {
	vector<int> res;
	int size = nums.size();

	// Ek doubly ended queue, ya doubly linked list
	list<int> highestEl;

	if (k > size)
		return {*max_element(nums.begin(), nums.end())};

	int i = 0, j = 0;
	while (j < size) {
		// Do the operation

		// If window size se chota hai
		if (j - i + 1 < k) {
			j++;
		} else if (j - i + 1 == k) {
			//


			// Slide krte hai
		}
	}
}