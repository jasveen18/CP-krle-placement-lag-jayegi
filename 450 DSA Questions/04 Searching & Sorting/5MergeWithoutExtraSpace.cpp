/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge 2 arrays without using extra space.

// Gaps to jump - modified ceil
int nextGap(int gap) {
	if (gap == 1 or gap == 0)
		return 0;
	else
		return (gap / 2) + (gap % 2);
}


void mergeBothArray(int arr1[], int arr2[], int n, int m) {
	int totalSize = n + m;
	// cout<<n<<" "<<m<<endl;

	for (int gap = nextGap(totalSize); gap > 0; gap = nextGap(gap)) {
		for (int i = 0; i < totalSize - gap; i++) {
			int j = i + gap;

			// Case 1: If both index lie in first arr
			if (i < n and j < n) {
				if (arr1[i] > arr1[j])
					swap(arr1[i], arr1[j]);
			}

			// Case 2: If i in first arr and j in second arr
			else if (i < n and j >= n) {
				if (arr1[i] > arr2[j - n])
					swap(arr1[i], arr2[j - n]);
			}

			// Case 3: Both index lie in second arr
			else if (i >= n and j >= n) {
				if (arr2[i - n] > arr2[j - n])
					swap(arr2[i - n], arr2[j - n]);
			}
		}
	}

	return;
}