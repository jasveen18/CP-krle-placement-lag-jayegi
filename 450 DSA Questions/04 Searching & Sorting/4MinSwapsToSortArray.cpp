/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the min of swaps required to make an array sorted.

// Approach 1 -
// Selection Sort takes the min number of swaps out of all sorting algorithms.
// T - O(N*N) | S - O(1)
int minSwapsToSort(vector<int> &nums, int n) {
	int swapsDone = 0;

	for (int i = 0; i < n; i++) {
		int minElementIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[minElementIdx] > nums[j])
				minElementIdx = j;
		}

		// Swap
		if (i != minElementIdx) {
			swap(nums[i], nums[minElementIdx]);
			swapsDone++;
		}
	}

	return swapsDone;
}


// Approach 2 -
// Graph method with one constraint that the elements should be between 0 to N-1.
// Cycle detect krenge and then unko break krne ke lie swaps krenge.
int minSwapsToSortGraph(vector<int> &nums, int n) {
	vector<pair<int, int>> arrPos(n);
	for (int i = 0; i < n; i++)
		arrPos.push_back({nums[i], i});

	sort(arrPos.begin(), arrPos.end());
	vector<bool> visited(n, false);

	int swapsRequired = 0;
	for (int i = 0; i < n; i++) {
		// Shii case hai, nothing required
		if (visited[i] or arrPos[i].second == i)
			continue;

		int cycleSize = 0;
		int j = i;
		while (!visited[j]) {
			visited[j] = true;
			j = arrPos[j].second;
			cycleSize++;
		}


		if (cycleSize > 0)
			swapsRequired += cycleSize - 1;
	}

	return swapsRequired;
}