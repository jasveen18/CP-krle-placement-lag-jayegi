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

// 3. Word Subsets
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
	// First process words2 -> max freq of each letter in each word. O(26 * N)
	unordered_map<int, int> freq;
	vector<int> maxrequired(26, 0);
	for (auto word : words2) {
		freq.clear();

		// Count
		for (auto ch : word) {
			freq[ch - 'a']++;
		}

		// Take max
		for (auto el : freq) {
			maxrequired[el.first] = max(maxrequired[el.first], el.second);
		}
	}

	// Now let's see in words1 for each word if it can satisfy max, it can satisfy all
	vector<string> res;
	freq.clear();

	for (auto word : words1) {
		bool yes = true;
		freq.clear();

		for (auto ch : word) {
			freq[ch - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (maxrequired[i] > freq[i]) {
				yes = false;
				break;
			}
		}

		if (yes)
			res.push_back(word);
	}

	return res;
}