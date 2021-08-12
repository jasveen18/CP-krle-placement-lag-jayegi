/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1.965. Univalued Binary Tree
bool isUnivalTree(TreeNode* root, TreeNode* parent = NULL) {
	if (root == NULL)
		return true;

	if (parent and root->val != parent->val)
		return false;

	bool left = isUnivalTree(root->left, root);
	bool right = isUnivalTree(root->right, root);

	return left and right;
}


// 2. 967. Numbers With Same Consecutive Differences
class Solution {
private:
	void findAll(int n, int k, vector<string> &res, string curr) {
		// Base
		if (n == 0) {
			res.push_back(curr);
			return;
		}

		// Recursive
		char digUp = curr[curr.size() - 1] + k;
		if (digUp <= '9')
			findAll(n - 1, k, res, curr + digUp);

		char digDown = curr[curr.size() - 1] - k;
		if (digDown >= '0' and digUp != digDown) // Extra check to remove duplicates when k = 0.
			findAll(n - 1, k, res, curr + digDown);

		return;
	}

public:
	vector<int> numsSameConsecDiff(int n, int k) {
		vector<string> res;
		for (int i = 1; i <= 9; i++) {
			string curr = "";
			curr += (i + '0');
			// cout<<curr<<endl;
			findAll(n - 1, k, res, curr);
		}

		vector<int> finalRes;
		for (auto num : res) {
			finalRes.push_back(stoi(num));
		}

		return finalRes;
	}
};

// 3. 966. Vowel Spellchecker
class Solution {
	string tolow(string s) {
		for (auto &c : s) {
			c = tolower(c);
		}

		return s;
	}

	string tonovowel(string s) {
		s = tolow(s);

		for (auto &c : s) {
			if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
				c = '#';
		}

		return s;
	}

public:
	vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
		unordered_set<string> words(wordlist.begin(), wordlist.end());
		unordered_map<string, string> capital, novowel;

		for (auto word : wordlist) {
			string cap = tolow(word);
			string dev = tonovowel(word);

			capital.insert({cap, word});
			novowel.insert({dev, word});
		}

		for (int i = 0; i < queries.size(); i++) {
			if (words.find(queries[i]) != words.end())
				continue;

			// Now we need to modify and check
			string lower = tolow(queries[i]);
			string novow = tonovowel(queries[i]);

			if (capital.find(lower) != capital.end()) {
				queries[i] = capital[lower];
			} else if (novowel.find(novow) != novowel.end()) {
				queries[i] = novowel[novow];
			} else {
				queries[i] = "";
			}
		}

		return queries;
	}
};