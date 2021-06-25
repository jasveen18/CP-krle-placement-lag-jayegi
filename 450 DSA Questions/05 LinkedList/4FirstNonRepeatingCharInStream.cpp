/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a string, find the first non repeating char if the string was in a stream.
// Input: A = "aabc"
// Output: "a#bb"

string FirstNonRepeating(string A) {
	queue<char> q;
	string res = "";

	int seen[26] = {0};

	for (int i = 0; i < A.size(); i++) {
		q.push(A[i]);
		seen[A[i] - 'a']++;

		while (!q.empty()) {
			if (seen[q.front() - 'a'] > 1)
				q.pop();
			else
				break;
		}

		if (q.empty()) {
			res += '#';
		} else {
			res += q.front();
		}
	}

	return res;
}