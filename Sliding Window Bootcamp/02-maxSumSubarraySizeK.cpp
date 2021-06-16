// *** Maximum / Minimum Sum Subarray of size K *** //

// Problem statement -
// what is the max sum in the subarray of size k?
// return integer -> max sum.

// Identification -
// 1. array dia hai.
// 2. subarray puch ra hai.
// 3. max puch ra hai.
// 4. size of window dia hai.

int maxSumSubarraySizeK(vector<int> &nums, int k) {
	int maxSum = INT_MIN;
	int runningSum = 0;
	int size = nums.size();

	int i = 0, j = 0;
	while (j < size) {
		// Add the current element
		runningSum += nums[j];

		// If window size hit ni kie hai toh j++ kr do
		if (j - i + 1 < k) {
			j++;
		} else if (j - i + 1 == k) { // If window size hit ho gyi hai toh max dekh lo and ek badha do.
			maxSum = max(maxSum, runningSum);
			runningSum -= nums[i];
			i++; j++;
		}
	}

	return maxSum;
}