// ** Stock Span Problem ** //

// Problem Statement -
// Given an array, stock prices of a stock.
// Output for each day, the number of consecutive elements (smaller and equal).

// Input -> 100, 80, 60, 70, 60, 75, 85

// for day 6 (75) wala ke lie,
// we will output -> 4 ---> [60, 70, 60, 75] (element bhi include ho jaega)

// Output -> 1 1 1 2 1 4 6

// Nearest Greater to left nikalo and wo element and curr ke beech ke elements ka count is the answer.

vector<int> stockSpan(vector<int> &prices) {
	int n = prices.size();
	stack< pair<int, int> > st;
	vector<int> res;

	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			res.push_back(i + 1);
		} else {
			while (st.empty() == false and st.top().first <= prices[i])
				st.pop();

			if (st.empty())
				res.push_back(i + 1);
			else
				res.push_back(i - st.top().second);
		}

		st.push({prices[i], i});
	}

	return res;
}