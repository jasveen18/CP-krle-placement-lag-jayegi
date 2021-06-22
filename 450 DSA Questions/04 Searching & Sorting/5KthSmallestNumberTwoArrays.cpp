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


// Approach 2 - Divide and Conquer OPOP (BS)
// T - O(min(LogN, LogM)) | S - O(1)
// Same as median of 2 sorted arrays.
int kthElement(int arr1[], int arr2[], int n, int m, k) {
	// arr1 will be larger
	if (n < m)
		return kthElement(arr2, arr1, m, n, k);

	int low = max(0, k - m), high = min(k, n);

	while (low <= high) {
		int cut1 = (low + high) / 2;
		int cut2 = k - cut1;

		int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; // if zero element bachta hai toh -inf lelo ni toh cut ke pehle wala
		int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

		int right1 = cut1 == n ? INT_MAX : arr1[cut1]; // if ek bhi element ni bacha to use at the 2nd part.
		int right2 = cut2 == m ? INT_MAX : arr2[cut2];

		// Now check if we did the correct partition or not
		if (left1 <= right2 and left2 <= right1) { // Shii partition
			return max(left1, left2);
		} else if (left1 > right2) {	// If shii partition ni hai toh phir BS jaise aage badho.
			high = cut1 - 1;
		} else {
			low = cut1 + 1;
		}
	}

	return 1;
}