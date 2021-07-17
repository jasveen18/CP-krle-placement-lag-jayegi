/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/


// 1. 1869. Longer Contiguous Segments of Ones than Zeros
bool checkZeroOnes(string s) {
	int ones = 0;
	int zeros = 0;

	int n = s.size();
	int max1 = 0;
	int max0 = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			zeros++;
			ones = 0;
		}

		if (s[i] == '1') {
			ones++;
			zeros = 0;
		}

		max0 = max(max0, zeros);
		max1 = max(max1, ones);
	}

	return max1 > max0;
}


// 2. 1870. Minimum Speed to Arrive on Time
bool isPossible(vector<int> &dist, double hour, int mid) {
	double timeRn = 0.0;

	for (int i = 0; i < dist.size() - 1; i++) {
		timeRn += ((dist[i] * 1.0) / mid);
		timeRn = ceil(timeRn);
	}

	timeRn += ((dist[dist.size() - 1] * 1.0) / mid);

	return timeRn <= hour;
}

int minSpeedOnTime(vector<int>& dist, double hour) {
	int start = 1, end = 10000000;
	int ans = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (isPossible(dist, hour, mid)) {
			ans = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}