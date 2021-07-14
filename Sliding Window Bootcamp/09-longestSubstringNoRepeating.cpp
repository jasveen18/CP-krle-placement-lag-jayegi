// *** Find Longest Substring With No Repeating Characters *** //

// Problem Statement ->
// title hi self-explanatory hai.

// Identification -
// String dia hai,
// Substring chaiye,
// K ni dia hai lekin jarurat ni hai, saare unique hone chaiye.
// Max chaiye

int longestSubstringAllUnique(string s) {
	int size = s.size();
	unordered_map<char, int> count;
	int res = INT_MIN;

	int i = 0, j = 0;
	while (j < size) {
		count[s[j]]++;

		if (count.size() == j - i + 1) {
			res = max(res, (j - i + 1));
			j++;
		} else if (count.size() < j - i + 1) {
			while (count.size() < j - i + 1) {
				count[s[i]]--;
				if (count[s[i]] == 0) // Remove element if count hits 0
					count.erase(s[i]);

				i++;
			}
		}
	}

	return res;
}