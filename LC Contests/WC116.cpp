/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 961. N-Repeated Element in Size 2N Array
int repeatedNTimes(vector<int>& A) {
	for (int i = 0; i < A.size() - 2; ++i)
		if (A[i] == A[i + 1] || A[i] == A[i + 2]) return A[i];
	return A[A.size() - 1];
}

// 2. 962. Maximum Width Ramp
int maxWidthRamp(vector<int>& nums) {
	vector<int> mark(5 * 10000 + 5, -1);
	int n = nums.size();

	for (int i = n - 1; i >= 0; i--) {
		int idx = i;
		int j = nums[i];
		while (j >= 0 and mark[j] == -1) {
			mark[j--] = idx;
		}
	}

	int res = INT_MIN;
	for (int i = 0; i < n; i++) {
		res = max(res, (mark[nums[i]] - i));
	}

	return res;
}