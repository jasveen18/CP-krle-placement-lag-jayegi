/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - First negative number in window of size k.

// Simple queue implementation
vector<long long> printFirstNegativeInteger(long long int nums[],
        long long int N, long long int k) {

	queue<long long> negNums;
	vector<long long> res;
	int size = N;

	int i = 0, j = 0;
	while (j < size) {
		// If negative then insert into queue
		if (nums[j] < 0)
			negNums.push(nums[j]);

		// If window size ni bana hai toh aage badho.
		if (j - i + 1 < k) {
			j++;
			// Do the calculations
		} else if (j - i + 1 == k) {
			// If queue is empty (koi neg num ni hai) toh zero
			if (negNums.size() == 0)
				res.push_back(0);
			else // else put the neg num
				res.push_back(negNums.front());

			// Slide the window now
			// Now if window ke bahar ke bahar chala jaara hai toh nikal do.
			if (negNums.size() != 0 and nums[i] == negNums.front())
				negNums.pop();
			i++; j++;
		}
	}

	return res;

}