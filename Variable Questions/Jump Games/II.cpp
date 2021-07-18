/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min number of jumps required to reach the end
// O(N) Time | O(1) Space
int jump(vector<int> &nums) {
	int jumps = 0;
	int currEnd = 0, currFarthest = 0;

	for (int i = 0; i < nums.size(); i++) {
		currFarthest = max(currFarthest, i + nums[i]);

		if (i == currEnd) {
			jumps++;
			currEnd = currFarthest;
		}
	}

	return jumps;
}