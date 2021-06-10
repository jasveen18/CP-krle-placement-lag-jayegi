// Brute force approach -
// Go for all the substrings of length (pattern)
// T - O(N*N)
int checkIfExists(string s, string pattern) {
	int n = s.size();
	int m = pattern.size();

	for (int i = 0; i + m <= s.size(); i++) {
		if (s.substr(i, m) == pattern)
			return i;
	}

	return -1;
}


// Using TRIE
// 1. Insert all the suffix of the text into tries
// Example - s = "abaac", then insert -> "abaac", "baac", "aac", "ac", "c".

struct trie {
	trie *nextChar[26];

	trie() {
		for (int i = 0; i < 26; i++) nextChar[i] = NULL;
	}
};


// Initialize root node.
trie root;
// root = new trie(); // Initialize this in main function.

void insertIntoTrie(string s) {
	trie *cur = root;

	for (int i = 0; i < s.size(); i++) {
		if (cur->nextChar[s[i] - 'a'] == NULL)
			cur->nextChar[s[i] - 'a'] = new trie();

		cur = cur->nextChar[s[i] - 'a'];
	}

	// Current pointer will be on the last node.
	cur->leafNode = true;
}


bool isPresentInTrie(string s) {
	trie *cur = root;

	for (int i = 0; i < s.size(); i++) {
		if (cur->nextChar[s[i] - 'a'] == NULL)
			return false;

		cur = cur->nextChar[s[i] - 'a'];
	}

	return true;
}


bool checkIfExists(string text, string pattern) {
	int n = text.size(), m = pattern.size();

	// Make trie
	for (int i = 0; i < n; i++) {
		insertIntoTrie(text.substr(i));
	}

	if (isPresentInTrie(pattern))
		return true;

	return false;
}