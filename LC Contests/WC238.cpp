/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 1837. Sum of Digits in Base K
int sumBase(int n, int k) {
	string converted = "";

	while (n) {
		converted += (n % k) + '0';
		n = n / k;
	}

	int res = 0;
	for (int i = 0; i < converted.size(); i++)
		res += converted[i] - '0';

	return res;
}


// 2. 1838. Frequency of the Most Frequent Element
int maxFrequency(vector<int>& A, int k) {
	sort(A.begin(), A.end());
	int n = A.size();

	long long res = 0;
	long long sum = 0;
	int i = 0, j = 0;

	while (j < n) {
		sum += A[j];

		// True case
		if (A[j] * (long long)(j - i + 1) - sum <= k) {
			res = max(res, (long long)j - i + 1);
			j++;
		} else {
			while (A[j] * (long long)(j - i + 1) - sum > k) {
				sum -= A[i];
				i++;
			}

			res = max(res, (long long)j - i + 1);
			j++;
		}
	}

	return res;
}


// 3. 1839. Longest Substring Of All Vowels in Order
int longestBeautifulSubstring(string word) {
	vector<pair<char, int>> inp;

	char curr;
	int count = 1;
	for (int i = 0; i < word.size() - 1; i++) {
		if (word[i] != word[i + 1]) {
			inp.push_back({word[i], count});
			count = 1;
		} else {
			count++;
		}
	}
	inp.push_back({word[word.size() - 1], count}); // Last element

	// Now I need to do pattern matching.
	// KMP laga le? // No fayda since LPS hai hi ni aeiou (pattern) mein
	// Sidha slide krte hai
	string pattern = "aeiou";
	if (inp.size() < 5)
		return 0;

	int res = 0;
	int i = 0, j = 0;
	while (i < inp.size()) {
		if (inp[i].first == pattern[j]) {
			i++; j++;
		}
		else {
			if (j != 0) // If already first pe the and tb bhi match ni hua toh increment i
				j = 0;
			else
				i++;
		}

		if (j == pattern.size()) {
			int start = i - 5;
			cout << start << endl;
			int count = 0;
			for (int x = start; x < start + 5; x++)
				count += inp[x].second;

			res = max(res, count);
			j = 0;
		}
	}

	return res;
}