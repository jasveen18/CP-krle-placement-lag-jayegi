// *** Longest Substring with K Unique Characters *** //

// Problem Statement - Find the longest substring with K unique characters

// Identification -
// String de rakhi hai.
// Substing puch ra hai.
// Longest nikalni hai and 'k' de rakha hai.

// variable size pe sbse pehla chiz is ki condition smjh aaye
// and usko mathematically represent krna aana chaiye, because usko compare krna hai k ke saath.

// Yaha pe condition is unique chars chaiye in the sliding window

// Approach ->
// Map use krenge for unique characters. Set use ni krenge, kyunki pta ni lagega

int longestSubstringKUnique(string s) {
	int size = s.size();
	unordered_map<char, int> count;
	int res = INT_MIN;

	int i = 0, j = 0;
	while (j < size) {
		count[s[j]]++;

		if (count.size() < k) {
			j++;
		} else if (count.size() == k) {
			res = max(res, (j - i + 1));
			j++;
		} else {
			while (count.size() > k) {
				count[s[i]]--;
				if (count[s[i]] == 0) // Remove element if count hits 0
					count.erase(s[i]);

				i++;
			}
		}
	}

	return res;
}