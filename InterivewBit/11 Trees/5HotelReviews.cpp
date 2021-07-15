/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find good words
class Trie {
private:
	class Node {
	public:
		Node* nextChar[26];
		bool leafNode;

		Node() {
			for (int i = 0; i < 26; i++) nextChar[i] = NULL;
			leafNode = false;
		}
	};

	Node* root;
public:
	Trie() {
		root = new Node();
	}

	void insertWord(string word) {
		Node* curr = root;
		for (int i = 0; i < word.size(); i++) {
			if (curr->nextChar[word[i] - 'a'] == NULL) {
				curr->nextChar[word[i] - 'a'] = new Node();
			}

			curr = curr->nextChar[word[i] - 'a'];
		}

		curr->leafNode = true;
	}

	bool searchWord(string word) {
		Node* curr = root;

		for (int i = 0; i < word.size(); i++) {
			if (curr->nextChar[word[i] - 'a'] == NULL)
				return false;

			curr = curr->nextChar[word[i] - 'a'];
		}

		return curr->leafNode;
	}
};

vector<string> breakStrings(string s) {
	vector<string> res;
	int n = s.size();
	string curr = "";

	for (int i = 0; i < n; i++) {
		if (s[i] == '_') {
			res.push_back(curr);
			curr = "";
		} else {
			curr += s[i];
		}
	}
	res.push_back(curr);

	return res;
}

bool comp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}


vector<int> Solution::solve(string A, vector<string> &B) {
	vector<string> goodwords = breakStrings(A);

	Trie* tr = new Trie(); // Initialize the trie

	// Push all the words
	for (int i = 0; i < goodwords.size(); i++) {
		tr->insertWord(goodwords[i]);
	}

	// Now I need to sort the strings
	vector<pair<int, vector<string> > > reviews;

	for (int i = 0; i < B.size(); i++) {
		reviews.push_back({i, breakStrings(B[i])});
	}

	vector<pair<int, int>> reviewsSorted;
	for (auto r : reviews) {
		int count = 0;
		for (int i = 0; i < r.second.size(); i++) {
			if (tr->searchWord(r.second[i]))
				count++;
		}

		reviewsSorted.push_back({r.first, count});
	}


	sort(reviewsSorted.begin(), reviewsSorted.end(), comp);

	vector<int> ans;
	for (auto r : reviewsSorted) {
		ans.push_back(r.first);
	}

	return ans;
}
