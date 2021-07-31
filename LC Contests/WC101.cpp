// 1.https://leetcode.com/contest/weekly-contest-101/problems/rle-iterator/
class RLEIterator {
public:
	vector<pair<int, int>> enc;
	int i;
	RLEIterator(vector<int>& encoding) {
		enc = vector<pair<int, int>>();

		// Store all the elements as a pair
		for (int i = 0; i < encoding.size(); i += 2) {
			if (encoding[i] == 0)
				continue;

			enc.push_back({encoding[i], encoding[i + 1]});
		}

		// Iterator
		i = 0;
	}

	int next(int n) {
		int res = -1;

		// Get rid of things smaller than n
		while (i < enc.size() and enc[i].first < n and n > 0) {
			n -= enc[i].first;
			enc[i].first = 0;
			i++;
		}

		if (i < enc.size()) {
			res = enc[i].second;
			enc[i].first -= n;
		}

		return res;
	}
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */