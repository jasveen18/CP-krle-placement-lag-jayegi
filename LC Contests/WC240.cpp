/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/


// 1. 1854. Maximum Population Year
int maximumPopulation(vector<vector<int>>& logs) {
	int n = logs.size();
	if (n == 0)
		return 0;

	// {count, year}
	vector<int> yearCount(101, 0);

	// Bruteforce
	for (int i = 0; i < n; i++) {
		for (int j = logs[i][0]; j < logs[i][1]; j++) {
			yearCount[j - 1950]++;
		}
	}

	// Find max
	int maxCount = 0;
	int maxYear = 0;

	for (int i = 0; i < yearCount.size(); i++) {
		if (yearCount[i] > maxCount) {
			maxCount = yearCount[i];
			maxYear = i + 1950;
		}
	}

	return maxYear;
}


// 2.1855. Maximum Distance Between a Pair of Values
int maxDistance(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();

	int i = n - 1, j = m - 1;
	int maxDist = 0;

	// nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
	// i<=j and nums1[i] <= nums2[j]
	// (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
	while (i >= 0 and j >= 0) {
		while (j >= 0 and nums1[i] > nums2[j])
			j--;

		maxDist = max(maxDist, j - i);
		i--;
	}

	return maxDist;
}