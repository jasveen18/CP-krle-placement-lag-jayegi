/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 1929. Concatenation of Array
vector<int> getConcatenation(vector<int>& nums) {
	int n = nums.size();
	nums.resize(2 * nums.size());

	for (int i = 0; i < n; i++) {
		nums[i + n] = nums[i];
	}

	return nums;
}


// 2. 1930. Number of 3 Letter Palindromes (Subsequence)
// We track the first and last occurence of each character.

// Then, for each character, we count unique characters between its first and last occurence. That is the number of palindromes with that character in the first and last positions.

// Example: abcbba, we have two unique chars between first and last a (c and b), and two - between first and last b (b and c). No characters in between c so it forms no palindromes.
// Legend Code -
int countPalindromicSubsequence(string s) {
	int first[26] = {[0 ... 25] = INT_MAX}, last[26] = {}, res = 0;

	for (int i = 0; i < s.size(); i++) {
		first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
		last[s[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++) {
		if (first[i] < last[i]) { // If element ka first and last is present
			res += unordered_set<char>(begin(s) + first[i] + 1, begin(s) + last[i]).size();
		}
	}

	return res;
}


// 4. 1932. Merge BSTs to Create Single BST
// Approach 1 - Build from root ->
// 1. Populate a hashmap {value: root} -> all root values are unique
// 2. Count values among trees
// 3. Indentify a root of the combined tree, it's value must be counted only once
// 4. Traverse from root, check BST validity, join leaves with roots, matching leaf and root values using map
// 5. If it combines all the trees, then return.

TreeNode* canMerge(vector<TreeNode*> &trees) {
	unordered_map<int, TreeNode*> m;
	unordered_map<int, int> cnt;

	for (auto &t : trees) {
		m[t->val] = t;
		cnt[t->val]++;
		cnt[t->left ? t->left->val : 0]++;
		cnt[t->right ? t->right->val : 0]++;
	}

	for (auto &t : trees) {
		if (cnt[t->val] == 1)
			return traverse(t, m) and m.size() == 1 ? t : NULL;
	}

	return NULL;
}


bool traverse(TreeNode* r, unordered_map<int, TreeNode*> &m, int min_left = INT_MIN, int max_right = INT_MAX) {
	if (r == NULL)
		return true;

	if (r->val <= min_left or r->val >= max_right)
		return false;

	if (r->left == r->left) {
		auto it = m.find(r->val);
		if (it != end(m) and r != it->second) {
			r->left = it->second->left;
			r->right = it->second->right;
			m.erase(it);
		}
	}

	return traverse(r->left, m, min_left, r->val) and traverse(r->right, m, r->val, max_right);
}