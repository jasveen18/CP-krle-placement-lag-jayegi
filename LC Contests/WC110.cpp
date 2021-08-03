// 1. Reorder Logs
static bool orderorder(pair<string, string> a, pair<string, string> b) {
	bool first = (a.second[0] >= 'a' and a.second[0] <= 'z');
	bool second = (b.second[0] >= 'a' and b.second[0] <= 'z');

	if (first and !second)
		return true;
	if (!first and second)
		return false;

	if (first and second) {
		if (a.second == b.second)
			return a.first < b.first;

		return a.second < b.second;
	}

	return false;
}

vector<string> reorderLogFiles(vector<string>& logs) {
	// break the identifier and content
	// sort in place with letter logs at first and their order
	vector<pair<string, string>> divlogs;
	for (int i = 0; i < logs.size(); i++) {
		string identifier = "";

		for (int j = 0; j < logs[i].size(); j++) {
			if (logs[i][j] == ' ') {
				break;
			} else {
				identifier += logs[i][j];
			}
		}

		string content = logs[i].substr(identifier.size() + 1);
		divlogs.push_back({identifier, content});
	}

	stable_sort(divlogs.begin(), divlogs.end(), orderorder);

	for (int i = 0; i < divlogs.size(); i++) {
		logs[i] = divlogs[i].first + " " + divlogs[i].second;
	}

	return logs;
}

// 2. 938. Range Sum of BST
class Solution {
	void inorder(TreeNode* root, int low, int high, int &sum) {
		if (root == NULL)
			return;

		inorder(root->left, low, high, sum);
		if (root->val >= low and root->val <= high)
			sum += root->val;
		inorder(root->right, low, high, sum);

		return;
	}

public:
	int rangeSumBST(TreeNode* root, int low, int high) {
		// Ek simple inorder kr denge toh ho jaega
		int sum = 0;
		inorder(root, low, high, sum);

		return sum;
	}
};


// 3. 939. Minimum Area Rectangle
int minAreaRect(vector<vector<int>>& points) {

	unordered_map<int, set<int> > p;

	for (int i = 0; i < points.size(); i++) {
		p[points[i][0]].insert(points[i][1]);
	}

	int res = INT_MAX;
	for (auto f : p) {
		for (auto s : p) {

			if (f.first == s.first)
				continue;

			vector<int> v(f.second.size());
			auto it = set_intersection(f.second.begin(), f.second.end(), s.second.begin(), s.second.end(), v.begin());

			int size = it - v.begin();
			if (size <= 1)
				continue;

			int minel = INT_MAX;
			for (int i = 0; i < size - 1; i++) {
				minel = min(minel, v[i + 1] - v[i]);
			}

			res = min(res, minel * abs(f.first - s.first));
		}
	}

	return res == INT_MAX ? 0 : res;
}


// 4. Distinct Subseq II
int distinctSubseqII(string s) {
	// Recurrance -> generate all subsequences
	// But, if there is a same element, then uss position pe we can
	// choose the last occured instead of the earlier ones

	int n = s.size();
	vector<int> dp(n + 1, 0);
	dp[0] = 1; // empty se start

	int mod = 1e9 + 7;

	vector<int> last(26, -1);

	for (int i = 0; i < n; i++) {
		int dig = s[i] - 'a';

		dp[i + 1] = dp[i] * 2 % mod;

		// Check if this letter was occured before?
		if (last[dig] >= 0) {
			dp[i + 1] -= dp[last[dig]];
		}

		dp[i + 1] %= mod;
		last[dig] = i;
	}

	dp[n]--; // remove the empty subseq
	return (dp[n] + mod) % mod;
}