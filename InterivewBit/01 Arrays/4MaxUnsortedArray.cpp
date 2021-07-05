/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.

vector<int> Solution::subUnsort(vector<int> &A) {
	vector<int>res;
	int f = INT_MIN;
	int l = INT_MAX;

	// Find the first anamoly
	for (int i = 0; i < A.size() - 1; i++) {
		if (A[i + 1] < A[i]) {
			l = i + 1;
		}
	}

	// Find the last anamoly
	for (int i = A.size() - 1; i > 0; i--) {
		if (A[i - 1] > A[i]) {
			f = i - 1;
		}
	}

	// If it is sorted, then return -1
	if (f == INT_MIN && l == INT_MAX) {
		res.push_back(-1);
		return res;
	}

	// Now, edge cases. If there are some elements inside the range which are smaller / greater than A[0] ... A[l] and A[r] .. A[n-1] respectively.
	int maximum = INT_MIN;
	int minimum = INT_MAX;

	for (int i = f; i <= l; i++) {
		minimum = min(minimum, A[i]);
		maximum = max(maximum, A[i]);
	}

	// Find those correct elements (handle the edge anamolies)
	int initial = upper_bound(A.begin(), A.begin() + f, minimum) - A.begin();
	int final = lower_bound(A.begin() + l + 1, A.end(), maximum) - A.begin() - 1;

	return {initial, final};
}
