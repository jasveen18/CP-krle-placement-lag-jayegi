// ** Nearest Greater to Left ** //

// Problem Statement ->
// Left m nearest greater kaun hai?

// Peechla question hi hai, traversal ko ulta kr denge bss na.

// Inp: 1 3 2 4
// Out: -1 -1 3 -1

// Isme brute force jo tha, second loop j from i-1 to 0, chalega

vector<int> prevLargerElement(vector<int> &nums) {
	int n = nums.size();

	stack<int> st;
	vector<int> res;

	for (int i = 0; i < n - 1; i++) {
		if (st.empty())
			res.push_back(-1);
		else { // Jab tk next greater ni milta keep on poping
			while (st.empty() == false and st.top() <= nums[i])
				st.pop();

			// Check for elements left
			if (st.empty())
				res.push_back(-1);
			else
				res.push_back(st.top());
		}

		st.push(nums[i]);
	}

	return res;
}
