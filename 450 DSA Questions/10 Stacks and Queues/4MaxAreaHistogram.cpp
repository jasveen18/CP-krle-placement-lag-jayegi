// ** Max Histogram Area ** //

// Problem Statement ->
// Find the max rectangular area that can be made by histogram.
// The histogram heights are given by the array.

// Input -> 6 2 5 4 5 1 6
// Ouput ->	12

// 5 4 5 wala se 4 * 3 lenge

// Approach ->
// Dono taraf se expand krna padega for each element.

// Smaller element lena hai to the left and right with indexes.
// NSL and NSR dono nikal lenge

long long largestAreaHistogram(vector<int> &nums) {
	int n = nums.size();
	stack< pair<int, int> > nsl;
	stack< pair<int, int> > nsr;

	vector<int> idxNSL;
	vector<int> idxNSR;

	// NSL find kr lete hai
	for (int i = 0; i < n; i++) {
		if (nsl.empty())
			idxNSL.push_back(-1);
		else {
			while (nsl.empty() == false and nsl.top().first >= nums[i])
				nsl.pop();

			if (nsl.empty())
				idxNSL.push_back(-1);
			else
				idxNSL.push_back(nsl.top().second);
		}

		nsl.push({nums[i], i});
	}

	// NSR find kr lete hai
	for (int i = n - 1; i >= 0; i--) {
		if (nsr.empty())
			idxNSR.push_back(n);
		else {
			while (nsr.empty() == false and nsr.top().first >= nums[i])
				nsr.pop();

			if (nsr.empty())
				idxNSR.push_back(n);
			else
				idxNSR.push_back(nsr.top().second);
		}

		nsr.push({nums[i], i});
	}
	reverse(idxNSR.begin(), idxNSR.end());


	long long res = INT_MIN;
	for (int i = 0; i < n; i++) {
		res = max(res, (idxNSR[i] - idxNSL[i] - 1) * nums[i]);
	}

	return res;
}