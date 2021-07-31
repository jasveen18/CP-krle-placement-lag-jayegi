// 1. 914. X of a Kind in a Deck of Cards
bool hasGroupsSizeX(vector<int>& deck) {
	unordered_map<int, int> freq;
	int minEl = INT_MAX;
	for (auto el : deck) {
		freq[el]++;
	}


	int g = 0;
	for (auto el : freq) {
		if (el.second < 2)
			return false;

		g = __gcd(el.second, g);
		if (g == 1)
			return false;
	}

	cout << endl;

	return true;
}