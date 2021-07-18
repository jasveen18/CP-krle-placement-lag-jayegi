// ** Next Largest Element ** //
// Nearest Greater to the right.

// Problem Statement -
// Next element jo curr element se bada hai.

// Inp -> 1 3 2 4
// Out -> 3 4 4 -1

// Brute force,
// for(i to n-1)
// 		for(j from i+1 to n)
// 			first element > A[i-1]
// j is dependant on i. Bss, stack lagane ki socho.

// O(N) Time | O(N) Space
// Every element may be seen max 2 times, jab tum pop kr dere ho peeche ke chote elements
// then wo elements toh kabhi ni aayenge,  current element next greater hoga hmesha.
vector<int> nextLargerElement(vector<int> &nums) {
	int n = nums.size();

	stack<int> st;
	vector<int> res;

	for (int i = n - 1; i >= 0; i--) {
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