/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.
int largestAreaHistogram(vector<int> &nums) {
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


	int res = INT_MIN;
	for (int i = 0; i < n; i++) {
		res = max(res, (idxNSR[i] - idxNSL[i] - 1) * nums[i]);
	}

	return res;
}


int Solution::maximalRectangle(vector<vector<int> > &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 1)
				matrix[i][j] += matrix[i - 1][j];
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, largestAreaHistogram(matrix[i]));

	return res;
}
