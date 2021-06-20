/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Searching in an array where adjacent differ by at most k
// Input : arr[] = {4, 5, 6, 7, 6}
//            k = 1
//            x = 6
// Output : 2
// The first index of 6 is 2.

// Approach -
// 1. Traverse one by one.
// 2. Since it is a step array, jump (arr[i] - x), the difference directly

int search(int arr[], int n, int target, int k) {
	int i = 0;

	while (i < n) {
		if (arr[i] == x)
			return i;

		// Jump the difference between current element and x / k.
		i = max(i, abs(arr[i] - x) / k);
	}

	return -1;
}