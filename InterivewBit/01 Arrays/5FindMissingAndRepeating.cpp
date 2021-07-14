/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the one repeating and one missing number in [1...N]. See 450
vector<int> Solution::repeatedNumber(const vector<int> &A) {
	int n = A.size();
	vector<int> res(n);
	int one = -1, two = -1;

	for (int i = 0; i < n; i++) {
		res[i] = A[i] - 1;
	}

	for (int i = 0; i < n; i++) {
		res[res[i] % n] += n;
	}

	for (int i = 0; i < n; i++) {
		res[i] /= n;

		if (res[i] == 2)
			one = i + 1;
		if (res[i] == 0)
			two = i + 1;
	}

	return {one, two};
}
