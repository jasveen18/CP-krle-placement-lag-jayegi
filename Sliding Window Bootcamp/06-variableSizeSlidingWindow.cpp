// ** Variable Size Sliding Window ** //

// Example se - Largest Subarray of Sum K.
// Problem Statement -
// Ek array and k dia hoga and bol dia hai ki longest subarray batao jiska sum = k hai.

// Fixed pe -> window size given, data(sum) variable
// Isme -> data(sum) given, window size variable

// Identification -
// 1. Array / String dia hoga
// 2. Subarray / Substring dia hoga
// 3. k dia hoga maybe, uska window size maximize kro ya minimize kro.

// This only works for positive numbers
int maxSizeWindowSumK(vector<int> &nums, int n) {
	int i = 0, j = 0, runningSum = 0;
	int longest = 0;

	while (j < n) {
		runningSum += nums[j];

		if (runningSum < k)
			j++;
		// Process
		else if (runningSum == k) {
			longest = max(longest, j - i + 1);
			j++;
		}
		// Sum > k
		else {
			while (runningSum > k) {
				runningSum -= A[i];
				i++;
			}
		}
	}

	return longest;
}