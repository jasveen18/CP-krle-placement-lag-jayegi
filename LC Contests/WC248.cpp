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
// Idea is to store 2 data into one element.
// So, jo original num hoga that will be -> (size * nums[i])
// And jo pehle tha waha pe that will be (nums[i] % size)

vector<int> buildArray(vector<int> &nums) {
	int n = nums.size();

	for (int i = 0; i < n; i++) {
		nums[i] = nums[i] + (n * (nums[nums[i]] % n));
	}

	for (int i = 0; i < n; i++)
		nums[i] /= n;

	return nums;
}


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


// 3. 1922. Count Good Numbers

long long modPower(long long a, long long b, long long mod) {
	long long res = 1;

	while (b) {
		if (b & 1)
			res = (res * a) % mod;

		a = (a * a) % mod;
		b = b >> 1;
	}

	return res;
}

int countGoodNumbers(long long n) {
	int ans;

	long long even = n / 2;
	long long odd = n / 2;
	long long mod = 1e9 + 7;

	if (n & 1)
		even++;

	long long e = 5;
	long long o = 4;
	long long evenPow = modPower(e, even, mod);
	long long oddPow = modPower(o, odd, mod);


	return ((evenPow % mod) * (oddPow % mod)) % mod;
}