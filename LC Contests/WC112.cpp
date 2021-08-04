/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 945. Minimum Increment to Make Array Unique
int minIncrementForUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	int res = 0, prev = 0;

	for (int i = 0; i < nums.size(); i++) {
		res += max(0, prev - nums[i]);
		prev = max(prev, nums[i]) + 1;
	}

	return res;
}


// 2. 946. Validate Stack Sequences
// Simulate the stack as it is
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	stack<int> st;
	int i = 0;

	for (auto num : pushed) {
		st.push(num);

		while (st.empty() == false and st.top() == popped[i]) {
			st.pop(); i++;
		}
	}

	return st.empty();
}

// 3. 947. Most Stones Removed with Same Row or Column
// Simple DFS or Union Find aisa kuch lag jayega.
// Idea is ki ek island pe sabko hata skte hai except one.

class Solution {
	unordered_map<int, int> parent;
	int numIslands = 0;

	int find(int x) {
		if (parent.count(x) == 0) {
			parent[x] = x; numIslands++; // Ek new banda mila hai.
		}

		if (parent[x] != x)
			parent[x] = find(parent[x]);

		return parent[x];
	}

	void uni(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			parent[s1] = s2;
			numIslands--; // Because now they are in the same island
		}
	}

public:
	int removeStones(vector<vector<int>>& stones) {
		// We will search on the index and not the points
		// A row index will connect 2 stones on this row
		// A col index will connect 2 stones on this col

		// The number of islands of points is same as number of islands with index

		// Row -> (0 to 10000)
		// Col -> (10000 to ..) // Actually ye 0 -> -1, 1 -> -2, 2 -> -3. Aisa ho jaega

		for (int i = 0; i < stones.size(); i++) {
			uni(stones[i][0], ~stones[i][1]);
		}

		return stones.size() - numIslands;
	}
};