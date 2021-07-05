/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1.1920. Build Array from Permutation

// O(N) T | O(N) S
vector<int> buildArray(vector<int>& nums) {
	vector<int> res(nums.size(), 0);
	for (int i = 0; i < nums.size(); i++) {
		res[i] = nums[nums[i]];
	}

	return res;
}

// O(N) T | O(1) S



// 2. 1921. Eliminate Maximum Number of Monsters
struct sortBy {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return (1.0 * a.first) / a.second > (1.0 * b.first) / b.second;
	}
};

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
	int n = dist.size();
	priority_queue<pair<int, int>, vector<pair<int, int>>, sortBy> pq;

	// Push all
	for (int i = 0; i < n; i++) {
		pq.push({dist[i], speed[i]});
	}

	int res = 0;
	int timer = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int speed = pq.top().second;

		if (speed * timer < dist)
			res++;
		else
			break;

		pq.pop();
		timer++;
	}

	return res;
}