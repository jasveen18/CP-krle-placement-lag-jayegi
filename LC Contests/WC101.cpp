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



// 2. Online Stock Span
class StockSpanner {
public:
	int i;
	stack<pair<int, int>> st;

	StockSpanner() {
		st = stack<pair<int, int>> ();
		i = 0;
	}

	int next(int price) {
		if (st.empty()) {
			st.push({price, i++});
			return 1;
		}  else {
			while (st.empty() == false and st.top().first <= price) {
				st.pop();
			}

			// Ekdum end m pahuch gye, sab koi hi chota hai merese
			if (st.empty()) {
				st.push({price, i++});
				return i;
			} else {
				int res = (i - st.top().second);
				st.push({price, i++});
				return res;
			}
		}

		return 1;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */