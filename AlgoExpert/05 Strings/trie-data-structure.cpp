struct trie {
	trie *nextChar[26];
	bool leafNode;

	trie() {
		for (int i = 0; i < 26; i++) nextChar[i] = NULL;
		leafNode = false;
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

	if (cur->leafNode)
		return true;
	else
		return false;
}