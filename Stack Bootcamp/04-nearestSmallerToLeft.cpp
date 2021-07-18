// ** Nearest Smaller to Left ** //

// Problem Statement ->
// Find the smaller element to left

// Ekdum same hai last time jaise,
// Bss pop ke time pe we will pop the larger elements

vector<int> prevLargerElement(vector<int> &nums) {
	int n = nums.size();

	stack<int> st;
	vector<int> res;

	for (int i = 0; i < n - 1; i++) {
		if (st.empty())
			res.push_back(-1);
		else { // Jab tk next smaller ni milta keep on poping
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

	return res;
}