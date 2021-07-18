// ** Nearest Smaller to Right ** //

// Again ekdum same, kr do waise hi code
vector<int> nextSmallerElement(vector<int> &nums) {
	int n = nums.size();

	stack<int> st;
	vector<int> res;

	for (int i = n - 1; i >= 0; i--) {
		if (st.empty())
			res.push_back(-1);
		else { // Jab tk next greater ni milta keep on poping
			while (st.empty() == false and st.top() >= nums[i])
				st.pop();

			// Check for elements left
			if (st.empty())
				res.push_back(-1);
			else
				res.push_back(st.top());
		}

		st.push(nums[i]);
	}

	reverse(res.begin(), res.end());
	return res;
}