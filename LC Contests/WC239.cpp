/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 1848. Minimum Distance to the Target Element
int getMinDistance(vector<int>& nums, int target, int start) {
	int i = start, j = start;
	int n = nums.size();

	while (i >= 0 or j < n) {
		int left = i >= 0 ? nums[i] : -1;
		int right = j < n ? nums[j] : -1;

		if (left == target)
			return abs(start - i);
		if (right == target)
			return abs(start - j);

		i--; j++;
	}

	return -1;
}




// 3.
void nextPermutation(string &s) {
	int n = s.size();
	int i = n - 2;

	while (i >= 0 and s[i] >= s[i + 1])
		i--;

	if (i == -1)
		return;

	int j = n - 1;
	while (j >= 0 and s[j] <= s[i])
		j--;

	swap(s[i], s[j]);
	reverse(s.begin() + i + 1, s.end());
	return;
}

int getMinSwaps(string num, int k) {
	// Idea is to brute force your way till kth permutation, and then count swaps
	string per = num;
	int n = num.size();

	for (int i = 0; i < k; i++)
		nextPermutation(per);

	// Count the number of swaps to reach
	int res = 0;
	int i = 0, j = 0;
	while (i < n) {
		j = i;

		while (num[j] != per[i])
			j++;

		// Now we found the elements, we will do the swaps
		while (i < j) {
			swap(num[j], num[j - 1]);
			j--;
			res++;
		}

		i++;
	}

	return res;
}