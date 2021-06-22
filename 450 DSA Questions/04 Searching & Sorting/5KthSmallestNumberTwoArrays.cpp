/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the kth smallest number when you merge 2 sorted arrays.

// Approach 1 -
// Time - O(K) | Space - O(1)
int kthElement(int arr1[], int arr2[], int n, int m, int k) {
	// 2 pointer appproach -
	if (k == 1)
		return min(arr1[0], arr2[0]);

	int i = 0, j = 0;
	int traversed = 0;
	int ans;

	while (traversed < k and i < n and j < m) {
		if (arr1[i] < arr2[j]) {
			ans = arr1[i++];
			traversed++;
		} else {
			ans = arr2[j++];
			traversed++;
		}
	}

	if (traversed == k)
		return ans;

	while (i < n and traversed < k) {
		ans = arr1[i++];
		traversed++;
	}
	while (j < m and traversed < k) {
		ans = arr2[j++];
		traversed++;
	}

	return ans;
}


// Approach 2 - Divide and Conquer OPOP
// T - O(min(LogN, LogM)) | S - O(1)
