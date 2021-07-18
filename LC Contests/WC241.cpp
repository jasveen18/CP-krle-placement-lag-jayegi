/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 1863. Sum of All Subset XOR Totals
void generateSubsets(vector<int> &nums, int index, int &ans, int curr) {
	// Base
	if (index == nums.size()) {
		ans += curr;
		return;
	}

	// Recursive
	// Include
	generateSubsets(nums, index + 1, ans, curr ^ nums[index]);
	// Exclude
	generateSubsets(nums, index + 1, ans, curr);

	return;
}

int subsetXORSum(vector<int>& nums) {
	// Considering constraints lets generate all subsets and take the answer
	int ans = 0;
	int currXor = 0;
	vector<int> temp;

	generateSubsets(nums, 0, ans, currXor);

	return ans;
}


// 2. 1864. Minimum Number of Swaps to Make the Binary String Alternating
int minSwaps(string s) {
	int ones = 0;
	int zeroes = 0;
	int n = s.size();

	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			zeroes++;
		else
			ones++;
	}

	if (abs(ones - zeroes) > 1)
		return -1;


	// Count the missed number in a valid alternating string (2 hi hoga);
	int missOne = 0, missZero = 0;
	for (int i = 0; i < n; i += 2) {
		missOne += s[i] != '1';
		missZero += s[i] != '0';
	}


	if (ones == zeroes)
		return min(missOne, missZero);

	if (ones > zeroes)
		return missOne;
	else
		return missZero;
}


// 3.1865. Finding Pairs With a Certain Sum
class FindSumPairs {
public:
	vector<int> n1, n2;
	unordered_map<int, int> c;
	FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
		n1 = vector<int> (begin(nums1), end(nums1));
		n2 = vector<int> (begin(nums2), end(nums2));

		// Store the count of each element
		for (int x : n2) c[x]++;

		// To break the search faster and using 2 sum approach
		sort(begin(n1), end(n1));
	}

	void add(int index, int val) {
		c[n2[index]]--; // This element won't be there anymore
		n2[index] += val; // Update the element
		c[n2[index]]++; // Insert the new element in the array
	}

	int count(int tot) {
		int ans = 0;

		for (int i = 0; i < n1.size() and n1[i] < tot; i++) {
			auto it = c.find(tot - n1[i]);

			if (it != c.end())
				ans += it->second;
		}

		return ans;
	}
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */



// 4. 1866. Number of Ways to Rearrange Sticks With K Sticks Visible
// We arrange our sticks right to left, and for each step we have only two choices:

// Pick the tallest stick. It will be visible from the left, so we just solve the subproblem for n - 1, k - 1.
// Pick any of the other n - 1 sticks. It does not matter which one since it will be covered by the tallest one.
// Then, we solve the subproblem for n - 1, k, multiplying the result by n - 1.

int dp[1001][1001] = {}, mod = 1e9 + 7;

int rearrangeSticks(int n, int k) {
	// Base Case
	if (k == n)
		return 1;

	if (dp[n][k] != 0)
		return dp[n][k];


	// Recursive Case
	if (k > 0 and n > k) {
		dp[n][k] = ((long)(n - 1) * rearrangeSticks(n - 1, k) + rearrangeSticks(n - 1, k - 1)) % mod;
	}

	return dp[n][k];
}
