/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min Char required to insert at beginning

// Each index of LPS array contains the longest prefix which is also a suffix.
// Now take the string and reverse of a string and combine them with a sentinal character in between them and compute the LPS array of this combined string.
// Now take the last value of the LPS array and subtract it with the length of the original string,
// This will give us the minimum number of insertions required in the begining of the string .

int Solution::solve(string A) {
	string rev = A;
	reverse(rev.begin(), rev.end());

	string targetString = A + '$' + rev;

	// Now we need to calculate the LPS array such as in KMP Algorithm
	vector<int> lps(targetString.size(), 0);
	int idx = 0;

	// KMP Algo ka LPS hai
	for (int i = 1; i < targetString.size(); ) {
		if (targetString[i] == targetString[idx]) {
			lps[i] = idx + 1;
			idx++; i++;
		} else {
			if (idx != 0) {
				idx = lps[idx - 1];
			} else {
				lps[idx] = 0;
				i++;
			}
		}
	}

	return A.size() - lps[targetString.size() - 1];
}
