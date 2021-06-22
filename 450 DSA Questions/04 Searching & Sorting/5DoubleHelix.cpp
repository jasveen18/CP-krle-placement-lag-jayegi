/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the max sum by traversing both arrays, you can pick one way and can change way when they have same element.

// 2 Pointer Approach
int maxSumTraversing(vector<int> &arr1, vector<int> &arr2, int n, int m) {
	int ans = 0;
	int runningSum1 = 0, runningSum2 = 0;
	int p1 = 0, p2 = 0;

	while (p1 < n and p2 < m) {
		if (arr1[p1] == arr2[p2]) {
			// Add to answer
			ans += max(runningSum1, runningSum2) + arr1[p1];

			// Reset back
			p1++; p2++;
			runningSum1 = 0;
			runningSum2 = 0;
		} else if (arr1[p1] < arr2[p2]) {
			runningSum1 += arr1[p1++];
		} else {
			runningSum2 += arr2[p2++];
		}
	}

	while (p1 < n) {
		runningSum1 += arr1[p1++];
	}

	while (p2 < m) {
		runningSum2 += arr2[p2++];
	}

	return ans + max(runningSum1, runningSum2);
}