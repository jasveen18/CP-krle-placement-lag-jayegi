// *** Meet me in the middle *** //

// Problem Statement 1 - Given a set of n integers where n <= 40. Each of them is at most 1012, determine the maximum sum subset having sum less than or equal S where S <= 1018.
// Problem Statement 2 - Given same things, find the number of subsets having sum larger than S.

// Approach -
// Kind of like DnC.
// Lekin here, we will divide the array into 2 parts and unke subset ka sum store kr lenge
// So, time taken will be O(2^(n/2)). Therefore, ye shii hai.
// Ab we want to merge both the arrays, toh iske lie we may again require O(2^(n/2) * 2) which is O(2^n).
// Toh same baat ho gye, therefore, we will sort the array Y and iterate over each value of X, and then we can use Binary Search to find the max element.

// Now, this would reduce our time complexity to - O(2^(n/2) * log(2^(n/2))) almost equivalent to O(N * 2^(n/2)).

// First Problem Statement pehle -

int x[2000005], y[2000005];
int maxSubsetSum(int arr[], int n, int s) {
	// Compute the subset sum of both halves
	createSubArraySum(arr, x, n / 2, 0);
	createSubArraySum(arr, x, n - n / 2, n / 2);

	int size_x = 1 << (n / 2);
	int size_y = 1 << (n - n / 2);

	// Sort the 2nd array so that we can do binary search on this.
	sort(y, y + size_y);

	int ans = 0;

	// Traverse over all the elements of x and do BS to find valid pairs.
	for (int i = 0; i < size_x; i++) {
		if (x[i] <= s) {
			int p = lower_bound(y, y + size_y, s - x[i]) - y;

			// if we don't find s-x[i], then usse ek niche wale ko hi le lenge
			if (p == size_y or y[p] != s - x[i])
				p--;

			ans = max(ans, y[p] + x[i]);
		}
	}

	return ans;
}