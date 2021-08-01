//1 . 922. Sort Array By Parity II
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& nums) {
		int even = 0;
		int odd = 0;
		int n = nums.size();

		while (even < n and nums[even] % 2 == 0)
			even += 2;

		if (even >= n)
			return nums;

		odd = 1;
		while (odd < n and nums[odd] % 2 == 1)
			odd += 2;


		while (even < n and odd < n) {
			swap(nums[even], nums[odd]);

			while (even < n and nums[even] % 2 == 0)
				even += 2;

			while (odd < n and nums[odd] % 2 == 1)
				odd += 2;
		}

		return nums;
	}
};

// 2. Min add to make paretheses valid
class Solution {
public:
	int minAddToMakeValid(string s) {
		int n = s.size();
		if (n == 0)
			return 0;

		int open = 0;
		int res = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				open++;
			else
				open--;

			if (open < 0) {
				res++;
				open = 0;
			}
		}

		return res + open;
	}
};