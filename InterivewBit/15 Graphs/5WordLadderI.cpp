/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

// You must change exactly one character in every transformation.
// Each intermediate word must exist in the dictionary.

// Approach 1 - TLE, BFS (intuitive)
int Solution::solve(string beginWord, string endWord, vector<string> &wordList) {
// Graph
	unordered_set<string> dict(wordList.begin(), wordList.end());

	queue<string> todo;
	todo.push(beginWord);

	int ladder = 1;

	while (todo.empty() == false) {
		int n = todo.size();

		for (int i = 0; i < n; i++) {
			string curr = todo.front(); todo.pop();

			// If found
			if (curr == endWord)
				return ladder;

			// If not found then remove this word from list to avoid inf loop
			dict.erase(curr);

			// Check if we can fit its neighbors(words differing by one char)
			for (int j = 0; j < curr.size(); j++) {
				char c = curr[j];

				for (int alpha = 0; alpha < 26; alpha++) {
					curr[j] = alpha + 'a'; // Saare combinations try kro

					if (dict.find(curr) != dict.end()) // If koi combination milta hai toh queue m daal do
						todo.push(curr);
				}

				// Backtrack
				curr[j] = c;
			}
		}

		ladder++;
	}

	return 0;
}


// Approach 2 - Two End BFS, we start from both ends and meet in the middle.
int Solution::solve(string beginWord, string endWord, vector<string> &wordList) {
	unordered_set<string> s1;
	unordered_set<string> s2;

	unordered_set<string> dict(wordList.begin(), wordList.end());

	// Element not found
	if (dict.find(endWord) == dict.end())
		return 0;

	int res = 0;

	s1.insert(beginWord);
	s2.insert(endWord);

	while (s1.empty() == false and s2.empty() == false) {
		res++; // Increment answer, ek baar jaare hai

		// Chote wale pe kro to minimize time
		if (s1.size() > s2.size())
			swap(s1, s2);

		unordered_set<string> cur;
		for (string word : s1) {
			for (int i = 0; i < beginWord.size(); i++) {
				char c = word[i];

				for (char x = 'a'; x <= 'z'; x++) {
					word[i] = x;

					// If found in 2nd set
					if (s2.find(word) != s2.end())
						return res + 1;
					if (dict.find(word) == dict.end()) // If the word is not present then move on
						continue;

					dict.erase(word);  // If present hai toh idhar se nikalo
					cur.insert(word);  // Idhar daal do
				}

				word[i] = c;
			}
		}

		s1 = cur;
	}

	return 0;
}