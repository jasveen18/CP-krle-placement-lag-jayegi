/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 1848. Minimum Distance to the Target Element
int getMinDistance(vector<int>& nums, int target, int start) {
	int i = start, j = start;
	int n = nums.size();

	while (i >= 0 or j < n) {
		int left = i >= 0 ? nums[i] : -1;
		int right = j < n ? nums[j] : -1;

		if (left == target)
			return abs(start - i);
		if (right == target)
			return abs(start - j);

		i--; j++;
	}

	return -1;
}

// 2. 1849. Splitting a String Into Descending Consecutive Values
bool splitString(string s, int i = 0, long prev = 0) {
	long num = 0;
	for (int j = i; num < 1e10 and j < s.size() - (i == 0 ? 1 : 0); j++) {
		num = num * 10 + (s[j] - '0');

		// Try with this combinations
		if ((i == 0 or prev - 1 == num) and splitString(s, j + 1, num))
			return true;
	}

	return i == s.size();
}


// 3. 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number
void nextPermutation(string &s) {
	int n = s.size();
	int i = n - 2;

	while (i >= 0 and s[i] >= s[i + 1])
		i--;

	if (i == -1)
		return;

	int j = n - 1;
	while (j >= 0 and s[j] <= s[i])
		j--;

	swap(s[i], s[j]);
	reverse(s.begin() + i + 1, s.end());
	return;
}

int getMinSwaps(string num, int k) {
	// Idea is to brute force your way till kth permutation, and then count swaps
	string per = num;
	int n = num.size();

	for (int i = 0; i < k; i++)
		nextPermutation(per);

	// Count the number of swaps to reach
	int res = 0;
	int i = 0, j = 0;
	while (i < n) {
		j = i;

		while (num[j] != per[i])
			j++;

		// Now we found the elements, we will do the swaps
		while (i < j) {
			swap(num[j], num[j - 1]);
			j--;
			res++;
		}

		i++;
	}

	return res;
}


// 4. 1851. Minimum Interval to Include Each Query

// Sort queries and intervals.
// Iterate queries from small to big,
// and find out all open intervals [l, r],
// and we add them to a priority queue.
// Also, we need to remove all closed interval from the queue.

// In the priority, we use
// [interval size, interval end] = [r-l+1, r] as the key.

// The head of the queue is the smallest interval we want to return for each query.
vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
	// Interval size, interval end -> r - l + 1, r
	priority_queue<vector<int>> pq;

	// To store the answer, and later re-order them into the order of queries
	unordered_map<int, int> mp;

	// Sort the intervals and queries
	vector<int> Q = queries, ans;
	sort(intervals.begin(), intervals.end());
	sort(Q.begin(), Q.end());

	int i = 0, n = intervals.size();
	for (auto q : Q) {
		while (i < n and intervals[i][0] <= q) {
			int l = intervals[i][0], r = intervals[i][1]; i++;

			// Notice ki yaha pe l - r - 1 daal re hai instead of r-l+1, to change order of PQ.
			pq.push({l - r - 1, r});
		}

		while (pq.size() and pq.top()[1] < q)
			pq.pop();

		mp[q] = pq.size() ? (-pq.top()[0]) : -1;
	}

	for (int q : queries)
		ans.push_back(mp[q]);

	return ans;
}