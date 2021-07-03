/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// BC 55

// 1. 1909 - Remove one element to make the array strictly increasing
bool canBeIncreasing(vector<int>& nums) {
	int n = nums.size();
	int lastSmallest = nums[0];
	int violations = 0;

	for (int i = 1; i < n; i++) {
		if (nums[i] <= lastSmallest) { // Not strictly increasing
			if (violations == 1)
				return false;

			violations++;

			// Update last smallest, we remove the element from i-1 position and take uske pehle wala solution
			if (i == 1 or nums[i] > nums[i - 2])
				lastSmallest = nums[i];
			// else remove the current element and leave last smallest as it is
		} else {
			lastSmallest = nums[i];
		}
	}

	return true;
}


// 1910. Remove All Occurrences of a Substring

// One way is O(N*M)
// Another way is to use KMP with stack
string removeOccurances(string a, string b) {
	int n = a.size();
	int m = b.size();

	// Temp pattern array
	vector<int> kmp(b.size() + 1);
	// Memo
	vector<int> idx(a.size() + 1);
	// Stack
	vector<int> st;

	// Make the KMP array
	for (int i = 1, j = 0; i < m;) {
		if (b[i] == b[j]) {
			kmp[++i] = ++j;
		} else {
			i += (j == 0);
			j = kmp[j];
		}
	}


	// traverse the strings
	for (int i = 0, j = 0; i < n; i++) {
		st.push_back(a[i]);

		if (st.back() == b[j]) {
			idx[st.size()] = ++j;

			if (j == m) {
				st.erase(st.begin() + st.size() - m, st.end());
				j = st.empty() ? 0 : idx[st.size()];
			}
		}

		else {
			if (j != 0) {
				i--;
				j = kmp[j];
				st.pop_back();
			}
		}
	}

	return string(st.begin(), st.end());
}