// 1. 914. X of a Kind in a Deck of Cards
bool hasGroupsSizeX(vector<int>& deck) {
	unordered_map<int, int> freq;
	int minEl = INT_MAX;
	for (auto el : deck) {
		freq[el]++;
	}


	int g = 0;
	for (auto el : freq) {
		if (el.second < 2)
			return false;

		g = __gcd(el.second, g);
		if (g == 1)
			return false;
	}

	cout << endl;

	return true;
}


// 2. 915. Partition Array into Disjoint Intervals
int partitionDisjoint(vector<int>& nums) {
	int n = nums.size();
	vector<int> rightmin(n);

	rightmin[n - 1] = nums[n - 1];
	for (int i = n - 2; i >= 0; i--)
		rightmin[i] = min(rightmin[i + 1], nums[i]);

	int maxleft = INT_MIN;
	for (int i = 0; i < n - 1; i++) {
		maxleft = max(nums[i], maxleft);

		if (maxleft <= rightmin[i + 1])
			return i + 1;
	}

	return n;
}